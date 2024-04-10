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
#define each(it,o) for(__typeof(o.begin()) it = o.begin; it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pii> vpii;

vi d[1000];
int main() {
    int n;
    scanf("%d",&n);
    string s;
    rep(i,n){
        int k;
        scanf("%d",&k);
        d[i].pb(0);
        rep(j,k) {
            int p;
            scanf("%d",&p);
            d[i].pb(p);
        }
        s+='\n';
        d[i].pb(INF);
        sort(all(d[i]));
    }
    puts(s.c_str());
    int r = 0;
    rep(i, n) {
        reu(j, 1, d[i].size()-2) {
            int x[2] = {0};
            rep(b, 2) {
            int k = (i+n+(!b?-1:1))%n;
            int lt, ut;
            {
                //
                int l = 0, u = d[k].size()-1;
                while((u-l)>1) {
                    assert(!(d[i][j] < d[k][l]));
                    assert(d[i][j] < d[k][u]);
                    int m = (u + l + 1) / 2;
                    if(d[i][j] < d[k][m]) {
                        u = m;
                    }else {
                        l = m;
                    }
                }
                lt = u;
            }
            {
                //
                int l = 0, u = d[k].size()-1;
                while((u-l)>1) {
                    assert(!(d[i][j+1] > d[k][u]));
                    assert(d[i][j+1] > d[k][l]);
                    int m = (u + l) / 2;
                    if(d[i][j+1] > d[k][m]) {
                        l = m;
                    }else {
                        u = m;
                    }
                }
                ut = l;
            }
//          cout << i << "," << j << "-" << b << ": " << lt << ", " << ut << " = " << (ut - lt + 1) << endl;
            x[b] = ut - lt + 1;
            }
            if(x[0] != x[1]) r ++;
        }
    }
    printf("%d\n", r);
    return 0;
}