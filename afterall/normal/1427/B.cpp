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
const int N=2e5+100;
int Main(){
    ll n,k;
    cin >> n >> k;
    ll val=0,t=0;
    string s;
    cin >> s;
    vector <int> a;
    ll last=-1;
    for (int i=0;i<s.size();i++){
        if (s[i]=='L') t++;
        else{
            if (last!=-1 && i-last-1>0){
                a.pb(i-last-1);
            }
            if (i==0) val++;
            else{
                if (s[i-1]==s[i]) val+=2;
                else val++;
            }
            last=i;
        }
    }
    if (k==0) kill(val);
    k=min(k,t);
    if (val==0){
        kill(2*(k-1)+1);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
   // cout << val << " " << s << " ";
    while(a.size() && a.back()<=k){
        val+=2*a.back()+1;
        k-=a.back();
        a.pop_back();
    }
    val+=2*k;
    kill(val);
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--){
        Main();
    }
}