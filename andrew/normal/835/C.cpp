#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
ll kek[102][102];
ll dp[15][102][102],a[100000],b[100000],c[100000],a1,b1,c1,n,m,x,i,j,sc,k;
string s;
int main(){
    ll i1,j1;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> c1;
    c1++;
    for(i=0;i<n;i++)cin >> a[i] >> b[i] >> c[i];
    for(i=0;i<n;i++)a[i]++,b[i]++;
    for(i=0;i<c1;i++)
    {
        //cout << i << endl;

         for(i1=1;i1<102;i1++)for(j1=1;j1<102;j1++)kek[i1][j1]=0;
     //cout << i << endl;
        for(j=0;j<n;j++)
        {
            if(c[j]>=c1)c[j]=0;
            kek[a[j]][b[j]]+=c[j];
            //cout << c[j] << "---" << endl;
            c[j]++;

        }
       // cout << i << endl;
    for(i1=1;i1<102;i1++)for(j1=1;j1<102;j1++)dp[i][i1][j1]=dp[i][i1-1][j1]+dp[i][i1][j1-1]-dp[i][i1-1][j1-1]+kek[i1][j1];
    }
    for(i=0;i<k;i++)
    {
        ll t1,x1,x2,y1,y2;
        cin >> t1 >> x1 >> y1 >> x2 >> y2;
        x1++,y1++,x2++,y2++;
        t1%=c1;
        //cout << t1 << endl;
        ll ans=dp[t1][x2][y2]-dp[t1][x1-1][y2]-dp[t1][x2][y1-1]+dp[t1][x1-1][y1-1];
        cout << ans << endl;
    }
return 0;
}