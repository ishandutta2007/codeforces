#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
using namespace std;
vector <ll> tt[1000];
string s,s1,s2;
char c1,c2,c3,c4;
pair <ll , ll >a[300001];
ll n,m,j,i,k,sc,v[300001],v1[300001],ans[300001],dd;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

   cin >> n >> k >> m;
   for(i=0;i<n;i++)
   {
         cin >> a[i].fi >> a[i].se;
         v[a[i].fi]++;
         v1[a[i].se]++;
   }
   ll kl=0;
   for(i=1;i<200001;i++)
   {
      dd+=v[i];
      ans[i]=ans[i-1];
      if(dd>=k)ans[i]++;
      dd-=v1[i];
   }
    for(i=0;i<m;i++)
    {
        ll x1,x2;
        cin >> x1 >> x2;
        cout << ans[x2]-ans[x1-1] << endl;
    }
    return 0;
}