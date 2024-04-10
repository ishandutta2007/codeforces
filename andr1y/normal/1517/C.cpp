// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 508;
ll a[N];
ll b[N][N];
ll did=0;
ll n;
void dfs(pll v, ll c){
    b[v.x][v.y]=c;
    did++;
    if(did==c) return;
    for(pll i : {make_pair(v.x-1, v.y), make_pair(v.x, v.y-1), make_pair(v.x+1, v.y), make_pair(v.x, v.y+1)}){
        if(i.x>0&&i.x<=n&&i.y>0&&i.y<=i.x&&b[i.x][i.y]==0&&did<c) dfs(i, c);
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin >> n;
    for(ll i = 1;i<=n;i++) cin >> a[i];
    memset(b, 0x3f, sizeof(b));
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=i;j++) b[i][j]=0;
        b[i][i]=a[i];
    }
    for(ll i = 1;i<=n;i++){
        did=0;
        dfs({i, i}, a[i]);
    }
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=i;j++)cout<<b[i][j]<<' ';
        cout<<'\n';
    }
}