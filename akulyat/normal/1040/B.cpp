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


ll n,i,j,k;
vector <ll> m;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;

ll s=0;
if (n%(2*k+1)>=k+1||n%(2*k+1)==0)
  s=k;

vector <ll> ans;
while (s<n)
  ans.push_back(s), s+=2*k+1;

cout<<ans.size()<<endl;
for (auto i:ans)
  cout<<i+1<<' ';







    return 0;
}