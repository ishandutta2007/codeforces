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
pll a[1000000];
string s,s1;
ll t1,t2,stn,mx,mp[1000000],i,j,n,m,k,sc,dp,x,b[100000],a1,b1,c1,ans;
int main() {

    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
   cin >> n;
   t1=-1;
   t2=-1;
   for(i=0;i<n;i++)cin >> a[i].fi >> a[i].se;
   sort(a,a+n);
   for(i=0;i<n;i++)
   {
       ll fl=0;
       if(t1<a[i].fi)
       {
           t1=a[i].se;
           fl=1;
       }
       if(t2<a[i].fi && fl==0)
       {
           t2=a[i].se;
           fl=1;
       }
       if(fl==0)
       {
           cout << "NO" << endl;
           return 0;
       }
   }
   cout << "YES" << endl;
    return 0;
}