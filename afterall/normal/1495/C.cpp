#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<long double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=5e2+10;
char c[N][N];
ll Main(){
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> c[i][j];
        }
    }
    if (n==1 || m==1){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout << "X" ;
            }
            cout << endl;
        }
        return 0;
    }
    for (int i=1;i<=n;i+=3){
        for (int j=1;j<=m;j++){
            c[i][j]='X';
        }
    }
    if (n%3==0){
        for (int j=1;j<=m;j++){
            if (c[n][j]=='X') c[n-1][j]='X';
        }
    }
    for (int i=1;i<=n;i+=3){
        if (i+3>n) continue;
        ll p1=0;
        for (int j=1;j<=m;j++){
            if (c[i+1][j]=='X' || c[i+2][j]=='X'){
                p1=1;
                c[i+1][j]='X';
                c[i+2][j]='X';
                break;
            }
        }
        if (p1==0){
            c[i+1][1]='X';
            c[i+2][1]='X';
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout << c[i][j] ;
        }
        cout << endl;
    }
    return 0;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}