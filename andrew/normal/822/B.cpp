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
set <ll> ss;
map < string , ll > mp;
string s,s1;
char c,cc;
ll sc,n,m,i,j,st[1000000],stn,a[1000000],b[100000],a1,b1,c1;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll mn=1e18;
    cin >> s >> s1;
    for(i=0;i<m-n+1;i++)
    {
         sc=0;
        for(j=0;j<n;j++)if(s1[i+j]!=s[j])sc++;
        if(mn>sc)
        {
            mn=sc;
            stn=0;
            for(j=0;j<n;j++)if(s1[i+j]!=s[j]){stn++;st[stn]=j+1;}
        }
    }
    cout << mn << endl;
    for(i=1;i<mn;i++)cout << st[i] << " ";
    if(mn!=0)cout << st[i] << endl;
    return 0;
}