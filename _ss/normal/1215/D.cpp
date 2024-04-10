#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=2e5+10,mod=1e9+7,inf=1e18;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    char c;
    int t1=0,t2=0,s1=0,s2=0;
    cin>>n;
    for (int i=1;i<=n/2;i++)
    {
        cin>>c;
        if (c!='?') s1+=c-'0';
        else t1++;
    }
    for (int i=1;i<=n/2;i++)
    {
        cin>>c;
        if (c!='?') s2+=c-'0';
        else t2++;
    }
    if (s1>s2)
    {
        swap(t1,t2);
        swap(s1,s2);
    }
    if (s1==s2)
    {
        if (t1!=t2) cout<<"Monocarp";
        else cout<<"Bicarp";
    }
    else
    {
        if (((t1-t2)/2*9)!=(s2-s1)) cout<<"Monocarp";
        else cout<<"Bicarp";
    }
    return 0;
}