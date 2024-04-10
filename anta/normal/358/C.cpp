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

const char * const pushops[3] = {
    "pushStack", "pushQueue", "pushFront"
};
const char * const popops[3] = {
    "popStack", "popQueue", "popFront"
};
int main() {
    int n;
    cin >> n;
    static int a[100001];
    rep(i, n) cin >> a[i];
    a[n] = 0;
    vpii v;
    rer(j, 0, n) if(a[j] == 0) {
        int i;
        for(i = j; i > 0 && a[i-1] != 0; i --) ;
        v.clear();
        reu(k, i, j) v.pb(mp(a[k], k));
        sort(all(v), greater<pii>());
        reu(k, i, j) {
            int t = -1;
            if((int)v.size() >= 1 && v[0].second == k) t = 0;
            if((int)v.size() >= 2 && v[1].second == k) t = 1;
            if((int)v.size() >= 3 && v[2].second == k) t = 2;
            if(t == -1) cout << "pushBack" << endl;
            else cout << pushops[t] << endl;
        }
        if(j == n) break;
        int num = min(3, (int)v.size());
        cout << num;
        rep(k, num) cout << " " << popops[k];
        cout << endl;
    }
    return 0;
}