#include <bits/stdc++.h>
/// this time?
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
const int N=3e2+100;
char a[N][N];
ll Main(){
    ll n,m;
    cin >> n >> m;
    ll p1=-1,p2=-1;
    ll p3=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> a[i][j];
            if (a[i][j]=='W'){
                if (p1!=-1 && (i+j)%2!=p1) p3=1;
                p1=(i+j)%2;
            }
            if (a[i][j]=='R'){
                if (p2!=-1 && (i+j)%2!=p2) p3=1;
                p2=(i+j)%2;
            }
        }
    }
    if (p3) kill("NO");
    if (p1==p2 && p1!=-1) kill("NO");
    cout << "YES" << endl;
    if (p1==-1 && p2==-1) p1=0,p2=1;
    if (p1==-1 && p2!=-1) p1=1-p2;
    if (p2==-1 && p1!=-1) p2=1-p1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if ((i+j)%2==p1) a[i][j]='W';
            else a[i][j]='R';
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}