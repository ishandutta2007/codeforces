#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define all(vr) vr.begin(),vr.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
const int N=2e6+10,N2=1e5+10;
int n,len=0;
string t[N2];
vector<int> vt[N2];
char ans[N];

void read()
{
    cin>>n;
    for (int i=1,x;i<=n;i++)
    {
        cin>>t[i]>>x;
        int l=t[i].length();
        for (int j=1,y;j<=x;j++) cin>>y,vt[i].pb(y),len=max(len,y+l-1);
    }
}

void process()
{
    set<int> st;
    for (int i=1;i<=len;i++) st.insert(i),ans[i]='a';
    for (int i=1;i<=n;i++)
    {
        int l=t[i].length();
        for (int x : vt[i])
        {
            auto it=st.lower_bound(x);
            while (it!=st.end() && *it<=x+l-1)
            {
                ans[*it]=t[i][*it-x];
                st.erase(it);
                it=st.lower_bound(x);
            }
        }
    }
    for (int i=1;i<=len;i++) cout<<ans[i];
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}