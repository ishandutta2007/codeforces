#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=2e5+100;
ll a[30];
void Main(){
    ll n;
   // cin >> n;
    string s;
    cin >> s;
    n=s.size();
    memset(a,0,sizeof a);
    ll last=n;
    for (int i=n-1;i>-1;i--){
        if (a[s[i]-'a']==0){
            last=i;
        }
        a[s[i]-'a']=1;
    }
    for (int i=last;i<n;i++) cout << s[i];
        cout << endl;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}