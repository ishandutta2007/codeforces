#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=2e5+1,msiz=2,mod=1e9+7,inf=1e18;
int vt[maxn],sl[maxn];
string s;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i=1;i<maxn;i++)
    {
        int x=i,d=0;
        while (x)
        {
            x>>=1;
            d++;
        }
        vt[i]=d;
    }
    int t;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>s;
        int d=0;
        for (int j=0;j<s.length();j++)
        {
            int v=0;
            for (int u=1;u<=min((int)(s.length())-j,20);u++)
            {
                v=(v<<1)+(s[j+u-1]-'0');
                if (v==u) d++;
            }
        }
        if (s.length()>20)
        {
        int k=0;
        for (int j=0;j<s.length();j++)
            if (s[j]=='1') sl[j]=k,k=0;
            else k++,sl[j]=0;
        for (int j=0;j<s.length();j++)
            if (sl[j])
            {
                int vl=0;
                for (int u=1;u<=vt[20];u++) vl=(vl<<1)+(s[u+j-1]-'0');
                for (int u=21;u<=s.length();u++)
                {
                    if (j+vt[u]-1>=s.length()) break;
                    if (vt[u]>vt[u-1]) vl=(vl<<1)+(s[j+vt[u]-1]-'0');
                    if (u-vt[u]>sl[j]) break;
                    if (vl==u) d++;
                }
            }
        }
        cout<<d<<endl;
    }
    return 0;
}