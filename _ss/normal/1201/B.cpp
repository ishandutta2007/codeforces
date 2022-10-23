#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+10;

int main()
{
    ll n,x,maxx=0,sumx=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&x);
        sumx+=x;
        maxx=max(maxx,x);
    }
    if ((sumx&1) || maxx>sumx/2) cout<<"NO"; else cout<<"YES";
    return 0;
}