#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,m,i,j,x;
vector <ll> v1,v2;
vector <ll> best1,best2;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  v1.push_back(a);
  }
for (i=0; i<m; i++)
  {
  ll a;
  cin>>a;
  v2.push_back(a);
  }
cin>>x;
vector <ll> pr1,pr2;
pr1.push_back(0);
for (auto i:v1)
  pr1.push_back(pr1.back()+i);
pr2.push_back(0);
for (auto i:v2)
  pr2.push_back(pr2.back()+i);

vector <pll> tos1,tos2;
tos1.push_back({0, 0});
tos2.push_back({0, 0});
for (i=0; i<n; i++)
  for (j=0; j<=i; j++)
    tos1.push_back({pr1[i+1]-pr1[j], i+1-j});
for (i=0; i<m; i++)
  for (j=0; j<=i; j++)
    tos2.push_back({pr2[i+1]-pr2[j], i+1-j});
sort(tos1.begin(), tos1.end());
sort(tos2.begin(), tos2.end());
vector <ll> best1,best2;
for (auto i:tos1)
  best1.push_back(i.S);
for (auto i:tos2)
  best2.push_back(i.S);
for (i=1; i<best1.size(); i++)
  best1[i]=max(best1[i], best1[i-1]);
for (i=1; i<best2.size(); i++)
  best2[i]=max(best2[i], best2[i-1]);

ll ans=0;
for (auto i:tos1)
  {
  ll p1=i.F;
  if (p1!=0)
    {
    ll p2=x/p1;
    ll place=(upper_bound(tos2.begin(), tos2.end(), make_pair(p2, inf))-tos2.begin());
    place--;
//    cout<<p1<<' '<<p2<<' '<<place<<endl;
    ll y=best2[place];
    ans=max(ans, i.S*y);
//    cout<<i.F<<' '<<i.S<<' '<<i.S*y<<endl;
    }
  }
cout<<ans<<endl;














    return 0;
}