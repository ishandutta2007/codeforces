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
int nt[101];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> snt;
    for (int i=2;i<51;i++)
        if (!nt[i])
        {
            for (int j=i*2;j<51;j+=i) nt[j]=1;
            snt.pb(i);
        }
    int d=0;
    string s;
    snt.pb(4);
    snt.pb(9);
    snt.pb(25);
    snt.pb(49);
    for (int i=0;i<snt.size();i++)
    {
        cout<<snt[i]<<endl;
        fflush(stdout);
        cin>>s;
        if (s=="yes") d++;
    }
    if (d<2) cout<<"prime"; else cout<<"composite";
    return 0;
}