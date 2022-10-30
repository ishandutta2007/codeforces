// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 3003;
const ll inf = 0x3f3f3f3f3f3f3f3f;
vector<ll> g[N];
ll d[5][N], res=-inf, s1, t1, l1, s2, t2, l2, n, m;
queue<ll> qq;

inline void updres(ll a, ll b, ll dist){
    if(d[0][a]+dist+d[1][b]<=l1 && d[2][a]+dist+d[3][b]<=l2){
        res=max(res, m-d[0][a]-d[1][b]-d[2][a]-d[3][b]-dist);
    }
    if(d[0][a]+dist+d[1][b]<=l1 && d[2][b]+dist+d[3][a]<=l2){
        res=max(res, m-d[0][a]-d[1][b]-d[2][b]-d[3][a]-dist);
    }
}
void cnt(ll q, ll v, bool c2=0){
    memset(d[q], 0x3f, sizeof(d[q]));
    d[q][v]=0;
    qq.push(v);
    if(c2) updres(v, v, 0);
    while(!qq.empty()){
       ll tv = qq.front();qq.pop();
       if(c2) updres(v, tv, d[q][tv]);
       for(auto i : g[tv]){
            if(d[q][i]==inf){
                d[q][i]=d[q][tv]+1;
                qq.push(i);
            }
       }
    }
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(ll a, b, i=0;i<m;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    cnt(0, s1);
    cnt(1, t1);
    cnt(2, s2);
    cnt(3, t2);
    if(d[0][t1]<=l1&&d[2][t2]<=l2)
        res=max(res, m-d[0][t1]-d[2][t2]);
    for(ll i = 1;i<=n;i++){
        cnt(4, i, 1);
    }
    cout<<max(res, -1ll)<<'\n';
}