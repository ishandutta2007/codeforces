#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t1=0,t2=0,x;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (x==1) t1++;
        else t2++;
    }
    if (t1>=t2) cout<<t2+(t1-t2)/3;
    else cout<<t1;
    return 0;
}