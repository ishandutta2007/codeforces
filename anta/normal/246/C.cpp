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
#define reps(i,n,s) for(int (i)=0;(i)<(int)(n);(i)+=(s))
#define reus(i,l,u,s) for(int (i)=(int)(l);(i)<(int)(u);(i)+=(s))
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

int a[55];
int main() {
    int n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    set<int> s;
    rep(i, k) {
        int xx = -1, xn = -1;
        while(1) {
            random_shuffle(a, a+n);
            int x = 0;
            rep(i, n) {
                x += a[i];
                if(!s.count(x)) {
                    xx = x; xn = i+1;
                    goto ok;
                }
            }
        }
ok:;
        cout << xn << " ";
        rep(i, xn) cout << a[i] << " ";
        cout << endl;
        s.insert(xx);
    }
    return 0;
}