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
const int N=6e5+100;
ll fen[4][N];
void add(ll id,ll idx,ll val){
    for (;idx<N;idx+=idx & (-idx)){
        fen[id][idx]+=val;
    }
}
ll get(ll id,ll idx){
    ll s=0;
    for (;idx;idx-=idx & (-idx)){
        s+=fen[id][idx];
    }
    return s;
}
ll a[N];
ll ans[N];
ll jav[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        ans[i]+=get(0,a[i])+a[i]*(i-1)+ans[i-1];
        for (int j=a[i];j<N;j+=a[i]){
            add(0,j,-a[i]);
          //  cout << j << " " << -a[i] << endl;
        }
      //  cout << ans[i] << " ";
    }
    for (int i=1;i<=n;i++){
        jav[i]=jav[i-1];
        for (int j=0;j<N-a[i];j+=a[i]){
            jav[i]+=-(get(2,j+a[i]-1)-get(2,j))*j+(get(1,j+a[i]-1)-get(1,j));
       //     if (-(get(2,j+a[i]-1)-get(2,j))*j+(get(1,j+a[i]-1)-get(1,j))>0 )
        }

        add(1,a[i],a[i]);
        add(2,a[i],1);
    }
    for (int i=1;i<=n;i++){
        cout << jav[i]+ans[i] << " ";
    }
}