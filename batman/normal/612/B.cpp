#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e14)
#define N (301*1000)

ll n,pos[N],ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        pos[a]=i;
    }
    for(int i=1;i<n;i++)
        ans+=abs(pos[i]-pos[i+1]);
    cout<<ans;  
    return 0;
}