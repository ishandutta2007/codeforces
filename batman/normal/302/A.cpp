#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e9)
#define N (301*1000)

ll n,m,num[2];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        if(a==-1)num[0]++;
        else num[1]++;
    }
    while(m--)
    {
        ll l,r;
        cin>>l>>r;
        if((r-l)%2==0){cout<<"0\n";continue;}
        ll ex=r-l+1;
        if(num[0]>=ex/2 && num[1]>=ex/2){cout<<"1\n";continue;}
        cout<<"0\n";
    }
    
    return 0;
}