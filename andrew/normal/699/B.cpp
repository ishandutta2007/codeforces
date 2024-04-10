#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
vector <pll> tt;
string s,s1,s2,s3;
char a[1001][1001];
ll kl,n,m,i,j,k,b[1001][1001],a1,b1,c1,c2,sc[1001],sc1[1001];
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        cin >> a[i][j];
        if(a[i][j]=='*')
        {
            sc[i]++;
            sc1[j]++;
            kl++;
        }
    }
    for(i=1;i<=n;i++)
    {
        ll dp=sc[i];
        for(j=1;j<=m;j++)
        {
          ll dp1=dp+sc1[j];
          if(a[i][j]=='*')dp1--;
          if(dp1==kl)
          {
              cout << "YES" << endl;
              cout << i << " " << j << endl;
              return 0;
          }
        }
    }
    cout << "NO" << endl;
    return 0;
}