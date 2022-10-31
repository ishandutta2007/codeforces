#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
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
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl; typedef pair<ll,ll> pll; typedef vector<pll> vpll; typedef vector<string> vs;
const int INF = 0x3f3f3f3f; const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
#define EPS 1e-9
int hl, hr, n;
int mv[111], ma[111], mb[111];
bool mc[111];
int len = 100000;
int main() {
    cin >> hl >> hr >> n;
    hl = 100-hl; hr = 100-hr;
    rep(i, n) {
        char h;
        cin >> mv[i] >> h >> ma[i] >> mb[i];
        mc[i] = h == 'F';
    }
    int r = 0;
    rer(i, 1, 100) rep(f, 2) {
        //f: 
        //0: , 1: 
        double a = i-1;
        double b1 = !f ? hl / 100. : 1 - hl / 100.;
        double b2 = !(f^(i%2!=0)^1) ? hr / 100. : 1 - hr / 100.;
        double t = len/(a+b1+b2);
        if(abs(a+b1+b2) < EPS) continue;
//      cerr << i << ", " << f << ": " << b1 << ", " << b2 << ", " << t << endl;
        vi v(n, 0);
        int pt = 0;
        rer(j, 1, i) {
            double x = t*(j-(1-b1));
            bool ft = ((f+(j-1))%2)!=0;
//          cerr << x << ", ";
            int kk = -1;
            rep(k, n) if(ma[k]-EPS <= x && x < mb[k]+EPS && mc[k] == ft) {
                kk = k;
                break;
            }
            if(kk == -1 || v[kk]) goto bad;
            v[kk] = 1;
            pt += mv[kk];
        }
        r = max(r, pt);
        cerr << i << ", " << f << ": " << pt << endl;
        bad:;
//      cerr << endl;
    }
    cout << r << endl;
    return 0;
}