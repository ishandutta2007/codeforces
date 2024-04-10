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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
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

struct RollingHash{
    static const unsigned long long p = 1000000007ULL;
    string s;
    int n;
    vector<unsigned long long> pow, phash;
    RollingHash(string s) : s(s), n(s.size()), pow(n+1), phash(n+1) {
        pow[0] = 1; phash[0] = 0;
        rep(i, n) {
            phash[i+1] = s[i] + phash[i] * p;
            pow[i+1] = pow[i] * p;
        }
    }
    unsigned long long h(int i) const {
        return phash[i];
    }
    unsigned long long h(int i, int j) const {
        return h(j) - h(i) * pow[j - i];
    }
};

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string bad;
    cin >> bad;
    int k;
    cin >> k;
    static int badcumsum[1502];
    rep(i, n) badcumsum[i+1] = bad[s[i]-'a'] == '0' ? 1 : 0;
    rer(i, 1, n) badcumsum[i] += badcumsum[i-1];
    RollingHash rh(s);
    int r = 0;
    rer(len, 1, n) {
        set<unsigned long long> e;
        for(int i = 0; i <= n - len; i ++) {
            if(badcumsum[i+len] - badcumsum[i] <= k) {
                e.insert(rh.h(i, i+len));
            }
        }
        r += e.size();
    }
    cout << r << endl;
    return 0;
}