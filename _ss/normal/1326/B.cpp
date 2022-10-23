#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=4e5+10;
ll b[N],n;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    ll mx=0;
    for (int i=1;i<=n;i++)
    {
        cout<<b[i]+mx<<" ";
        mx=max(mx,b[i]+mx);
    }
    return 0;
}