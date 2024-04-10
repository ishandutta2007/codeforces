#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

struct FenwickTree {
    typedef int T;
    vector<T> v; int highestOneBit;
    FenwickTree() { }
    void init(int n) {
        highestOneBit = 1; while(highestOneBit * 2 <= n) highestOneBit *= 2;
        v.assign(n+1, T());
    }

    template<typename U> void init(const U *a, int n) {
        highestOneBit = 1; while(highestOneBit * 2 <= n) highestOneBit *= 2;
        v.resize(n+1);
        for(int i = 0; i < n; i ++) v[i+1] = a[i];
        for(int i = 1; i <= n; i ++) {
            int j = i + (i & -i);
            if(j <= n) v[j] += v[i];
        }
    }

    void add(int i, T x) {
        int n = v.size();
        for(i ++; i < n; i += i & -i) v[i] += x;
    }
    T sum(int i) const {    //[0, i)
        T r = 0;
        for( ; i > 0; i -= i & -i) r += v[i];
        return r;
    }
    T sum(int left, int right) const {  //[left, right)
        return sum(right) - sum(left);
    }
    int kth(T x) const {
        int n = v.size(), i = 0;
        for(int b = highestOneBit; b != 0 && i < n; b >>= 1) {
            if(i + b < n) {
                int t = i + b; T u = v[t];
                if(x >= u) { i = t; x -= u; }
            }
        }
        return x != 0 ? -i : i;
    }
};


int p[1000000], pos[1000001];
bool used[1000000];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, n) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    rep(i, m) {
        int x;
        scanf("%d", &x);
        used[pos[x]] = true;
    }
    FenwickTree t, s;
    t.init(used, n); s = t;
    int stotal = m;
    ll ans = 0;
    for(int x = n; x >= 1; x --) {
        int k = pos[x];
        if(!used[k]) {
            t.add(k, 1);
            int ksum = s.sum(k);
            int left = ksum == 0 ? 0 : s.kth(ksum - 1) + 1;
            int right = ksum == stotal ? n-1 : s.kth(ksum) - 1;
            ans += t.sum(left, right+1);
//          cerr << x << ", " << k << ": " << left << ", " << right << ", " << t.sum(left, right+1) << "; " << ksum << ", " << stotal << endl;
        }else {
            s.add(k, -1);
            stotal --;
        }
    }
    cout << ans << endl;
    return 0;
}