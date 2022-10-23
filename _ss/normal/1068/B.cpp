#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;

int main()
{
    ll b,ans=0;
    cin>>b;
    for (ll i=1;i*i<=b;i++)
        if (b%i==0)
        {
            if (b/i==i) ans++;
            else ans+=2;
        }
    cout<<ans;
    return 0;
}