// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 303;
char a[N][N], b[N][N], pek[N][N];
pll p[N][N];
vector<pll> c[N][N];
pll f(pll a){
    return p[a.x][a.y]==a?a:p[a.x][a.y]=f(p[a.x][a.y]);
}
void u(pll a, pll b){
    a=f(a), b=f(b);
    if(a==b) return;
    if(c[a.x][a.y].size()>c[b.x][b.y].size()) swap(a, b);
    p[a.x][a.y]=b;
    for(auto &i : c[a.x][a.y]) c[b.x][b.y].push_back(i);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<n;j++){
                p[i][j]={i, j};
                c[i][j].clear();
                c[i][j].push_back({i, j});
                cin >> a[i][j];
                if(a[i][j]!='.'&&i&&a[i-1][j]!='.') u({i, j}, {i-1, j});
                if(a[i][j]!='.'&&j&&a[i][j-1]!='.') u({i, j}, {i, j-1});
                b[i][j]=a[i][j];
            }
        }
        map<pll, bool> was;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<n;j++){
                pll e = f({i, j});
                if(was[e]) continue;
                was[e]=1;
                ll mrr = c[e.x][e.y].size();
                vector<ll> p = {0, 1, 2};
                do{
                    for(ll inv=0;inv<2;inv++){
                        ll rr=0;
                        for(auto &q : c[e.x][e.y]){
                            ll i = q.x, j=q.y;
                            b[i][j]=a[i][j];
                            ll pi = i%3, pj = j%3;
                            bool mbo = (p[pi]==pj)^inv;
                            if((mbo&&b[i][j]=='X')||(!mbo&&b[i][j]=='O')) rr++, b[i][j]=('X'+'O'-b[i][j]);
                        }
                        if(rr<mrr){
                            mrr=rr;
                            for(auto &q : c[e.x][e.y]){
                                ll i = q.x, j=q.y;
                                pek[i][j]=b[i][j];
                            }
                        }
                    }
                }while(next_permutation(begin(p), end(p)));
            }
        }
        for(ll i = 0;i<n;i++){
            for(ll j =0;j<n;j++){
                cout<<pek[i][j];
            }
            cout<<'\n';
        }
    }
}