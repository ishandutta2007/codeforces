#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
typedef complex<double> point;
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
const int N=520;
ll b[N];
ll ans[N][N];
int Main(){
    ll n;
    cin >> n ;
    vector <int> a;
    for (int i=1;i<=n;i++){
        cin >> ans[i][i];
    }
    for (int i=1;i<=n;i++){
        ll cnt=1;
        ll last=i;
        for (int j=i;j<=n;j++){
            last++;
            if (ans[j][cnt]-i==0) break;
            ans[j+1][cnt]=ans[j][cnt];
            cnt++;
        }
        cnt++;
        for (int j=last;j<=n;j++){
            ans[j][cnt-1]=ans[j][cnt];
            cnt++;
        }

    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}
int32_t main(){
    sync;
    ll t=1;
    //cin >> t;
    while(t--){
        Main();
    }
}