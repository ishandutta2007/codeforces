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

int main() {
    int n;
    cin >> n;
    vpii pos;
    vi ys(n), xs(n);
    rep(i, n-1) {
        int x, y;
        cin >> y >> x; x--, y--;
        pos.pb(mp(x,y));
        ys[y] ++, xs[x] ++;
    }
    int n0 = n;
    stringstream rr; int rn = 0;
    while(1) {
#ifdef _DEBUG
        rep(i, n0) {
            rep(j, n0) cerr << "01"[count(all(pos),mp(j,i))];
            cerr<<endl;
        }
        cerr<<endl;
#endif
        if(n==1)break;
        //1columns
        rep(i, n) if(xs[i] == 0) {
            //swap
            if(i != n-1) {
                rr << 2 << " " << (i+1) << " " << n << endl; rn ++;
            }
            rep(k, pos.size()) {
                if(pos[k].first == i) pos[k].first = n-1;
                else if(pos[k].first == n-1) pos[k].first = i;
            }
            //0
            rep(j, n) if(ys[j] != 0) {
                if(j != n-1) {
                    rr << 1 << " " << (j+1) << " " << n << endl; rn ++;
                }
                rep(k, pos.size()) {
                    if(pos[k].second == j) pos[k].second = n-1;
                    else if(pos[k].second == n-1) pos[k].second = j;
                }
                break;
            }
            n --;
            xs.assign(n, 0); ys.assign(n, 0);
            rep(k, pos.size()) {
                if(pos[k].first < n && pos[k].second < n) {
                    xs[pos[k].first] ++;
                    ys[pos[k].second] ++;
                }
            }
            break;
        }
    }
    cout << rn << endl;
    cout << rr.str();
    return 0;
}