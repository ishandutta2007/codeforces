#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e9)
#define N (301*1000)
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;a;}return p;}

ll n,x,p;
string ex,ans;
bool a[N];

ifstream fin("input.txt");

void solve()
{
    p--;
    if(a[x++])
        ans+="pair<",solve(),ans+=",",solve(),ans+=">";
    else    
        ans+="int";   
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(p=0;cin>>ex;p++)
        a[p]=(ex=="pair");
    solve();  
    if(p)
        cout<<"Error occurred";
    else
        cout<<ans;  
    return 0;
}