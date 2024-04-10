#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define N (301*1000)
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

string s;
ll m;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>m;
    while(m--)
    {
        string ex="";
        ll l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        for(int i=0;i<l;i++)ex+=s[i];
        k%=(r-l+1);
        //cout<<r-k+1<<" "<<r<<endl;
        for(int i=r-k+1;i<=r;i++)ex+=s[i];
        for(int i=l;i<r-k+1;i++)ex+=s[i];
        for(int i=r+1;i<s.size();i++)ex+=s[i];
        s=ex;
        //cout<<s<<endl;
    }
    cout<<s;
    return 0;
}