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
ll Main(){
   ll n;
   cin >> n;
   string s;
   cin >> s;
   string t="";
   ll p1=0,p2=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='(') p1++;
        else p1--;
    }
    if (p1!=0) kill("NO");
    for (int i=0;i<n;i++){
        if (s[i]==')' && p2==0){
            p2=1;
            continue;
        }
        else{
            t+=s[i];
        }
    }
    t+=')';
    p2=0;
    for (int i=0;i<t.size();i++){
        if (t[i]=='(') p1++;
        else p1--;
        if (p1<0) p2=1;
    }
    if (p2==0) kill("YES");
    t="";
    p2=0;
    for (int i=n-1;i>-1;i--){
        if (s[i]=='(' && p2==0){
            p2=1;
        }
        else{
            t+=s[i];
        }
    }
    s+='(';
    reverse(s.begin(),s.end());
    p2=0;
    p1=0;
     for (int i=0;i<t.size();i++){
        if (t[i]=='(') p1++;
        else p1--;
        if (p1<0) p2=1;
    }
    if (p2==0) kill("YES");
    kill("NO");

}
int32_t main(){
    ll t;
  //  cin >> t;
  t=1;
    while(t--) Main();
}