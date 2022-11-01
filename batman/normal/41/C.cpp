#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1001*1000)
#define INF ((ll)1e7)

string s,ans;
ll n;
bool mark;

int main ()
{
    cin>>s;
    n=s.size();
    s+="...";
    cout<<s[0];
    for(int i=1;i<n;i++)
    {
        if(s[i]=='d' && s[i+1]=='o' && s[i+2]=='t' && i<n-3)
            cout<<'.',i+=2;
        else if(s[i]=='a' && s[i+1]=='t' && i<n-2 && !mark)
            mark=1,cout<<'@',i++;
        else
            cout<<s[i];     
    }
    
    return 0;
}