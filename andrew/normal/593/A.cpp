#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
vector <ll> tt[1000];
string s[1000];
ll cc[1000][1000];
ll fl,p[1000000],i,j,n,m,k,sc,dp,x,a[100000],b[100000],a1,b1,c1,ans,mx;
int main() {
     ll i1,j1;
    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> s[i];
        m=s[i].size();
        for(j=0;j<m;j++)cc[i][s[i][j]]=1;
    }
    for(i='a';i<='z';i++)
        for(j='a';j<='z';j++)
        {
            sc=0;
            for(i1=1;i1<=n;i1++)
            {
                fl=0;
                for(j1='a';j1<='z';j1++)if(cc[i1][j1]!=0 and j1!=j and j1!=i)fl=1;
                if(fl==0)sc+=s[i1].size();
            }
            mx=max(mx,sc);
        }
     cout << mx << endl;
    return 0;
}