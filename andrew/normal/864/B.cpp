#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
vector <ll> tt[1000];
map <ll,ll> mp,mp1;
string s,s1,s2;
char cc;
ll stn,p[1000000],i,j,n,m,k,sc,dp[1000000],x,a[100000],b[100000],a1,b1,c1,ans;
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s;
    for(cc='A';cc<='Z';cc++)s2+=cc;
    for(i=0;i<n;i++)
    {
        cc=s[i];
        int kek=s2.find(cc);
        if(kek!=-1)
        {
            sc=0;
            for(j=0;j<26;j++)if(a[j]!=0)sc++;
            ans=max(ans,sc);
            for(j=0;j<26;j++)a[j]=0;
            continue;
        }
        else
        {
            a[cc-'a']++;
        }
    }
    sc=0;
    for(j=0;j<26;j++)if(a[j]!=0)sc++;
    cout << max(ans,sc) << endl;
    return 0;
}