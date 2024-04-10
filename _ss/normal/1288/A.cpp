#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int cal(int x,int d)
{
    return (x+(d-1)/(x+1)+1);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,d;
        cin>>n>>d;
        int x=0;
        while (cal(x,d)>=cal(x+1,d)) x++;
        if (cal(x,d)<=n) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}