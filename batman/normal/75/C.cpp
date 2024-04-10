#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF (0x3f3f3f3f)

ll a,b,n;
set <ll> s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b;
    for(ll i=1;i*i<=a;i++)
        if(a%i==0)
        {
            if(b%i==0)
                s.insert(i);
            if(b%(a/i)==0)
                s.insert((a/i));    
        }
    //for(set <ll>::iterator it=s.begin();it!=s.end();it++)cout<<*it<<"\n"; 
    cin>>n;
    while(n--)
    {
        ll l,r;
        cin>>l>>r;
        set <ll>::iterator it=s.upper_bound(r);
        if(it==s.begin()){cout<<"-1\n";continue;}
        it--;
        if(*it<l){cout<<"-1\n";continue;}
        cout<<*it<<"\n";    
    }   
        
    return 0;
}