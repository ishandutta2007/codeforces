#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=1e18;

string s;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int flag=1;
    for (int i=1;i<s.length();i++)
        if (s[i]=='1') flag=0;
    if (s.length()>1) cout<<(s.length()-flag-1)/2+1;
    else cout<<0;
    return 0;
}