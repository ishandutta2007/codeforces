#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
const ll shl=1;
const ll maxn=1000000;
set <ll> ss;
map < string , ll > mp;
string s,s1;
ll cc[1000000];
vector <ll> tt[1000000];
ll q1,q2,q[1000000],rr,l,r,t[100][100],k,c,sc,n,m,i,j,a[1000000],b[1000000],t1[1000000],t2[100][100],a1,b1,c1,ans,x;
void add(ll x)
{
    if(t1[x]!=0)return;
    t1[x]=rr;
    q[q1]=x;
    q1++;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll i1,j1;
  cin >> n;
  for(i=0;i<n;i++)cin >> a[i];
  for(i=0;i<n;i++)b[i]=a[i];
  sort(b,b+n);
  for(i=0;i<n;i++)
  {
      l=0;
      r=n-1;
      x=a[i];
      while(l<r)
      {
        c=(l+r)/2;
        if(b[c]<x)l=c+1;else r=c;
      }
      cc[i]=l;
  }
rr=0;
    for(i=0;i<n;i++)if(a[i]==b[i])
    {
        rr++;
        t1[i]=rr;
    }
  for(i=0;i<n;i++)if(t1[i]==0)
  {
      rr++;
      q1=q2=0;
      add(i);
      while(q1!=q2)
      {
         x=q[q2];
         add(cc[x]);
         q2++;
      }
     // cout << q2 << endl;
  }
  cout << rr << endl;
  for(i=0;i<n;i++)tt[t1[i]].p_b(i);
  for(i=1;i<=rr;i++)
  {
      cout << tt[i].size();
      for(j=0;j<tt[i].size();j++)cout << " " << tt[i][j]+1;
      cout << endl;
  }
    return 0;
}