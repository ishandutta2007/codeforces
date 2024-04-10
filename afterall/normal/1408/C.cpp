#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e5+100;
ll a[N];
int Main(){
    ll n,l;
    cin >> n >> l;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ld t=0;
    ld p1=0,p2=l;
    ll po=1,op=n;
    ld s1=1,s2=1;
    for (int k=1;k<=n;k++){
        ld dis1=a[po]-p1,dis2=p2-a[op];
        dis1/=(ld)s1;
        dis2/=(ld)s2;
        if (dis1<dis2){
            t+=dis1;
            p2-=dis1*s2;
            po++;
            p1+=dis1*s1;
            s1++;
        }
        else{
            t+=dis2;
            p2-=dis2*s2;
            op--;
            s2++;
            p1+=dis2*s1;
        }

    }
    ld dis=p2-p1;
    dis/=(ld)(s1+s2);
    t+=dis;
    cout << fixed << setprecision(10) << t   << endl;
}
int32_t main(){
    sync;
    ll t;
    t=1;
    cin >> t;
    while(t--) Main();
}