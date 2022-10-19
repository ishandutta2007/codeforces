#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=30;
ll ans[N][N];
int Main(){
    ll h,w;
    cin >> h >> w;
    memset(ans,0,sizeof ans);
    for (int i=1;i<=w;i+=2){
        ans[1][i]=1;
    }
    for (int i=2;i<=h;i+=2){
        if (i==2 && (ans[1][w]==1 || ans[1][w-1]==1)) i++;
        ans[i][w]=1;
    }
    for (int i=w-1;i>0;i-=2){
        if (i==w-1 && (ans[h][w]==1 || ans[h-1][w]==1)) i--;
        ans[h][i]=1;
    }
    for (int i=h-1;i>2;i-=2){
        if (i==h-1 && (ans[h][1]==1 || ans[h][2]==1)) i--;
        if (i<=2) break;
        ans[i][1]=1;
    }
    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}