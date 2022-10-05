#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
ifstream in;
ofstream out;

ll n,i,j,k;
vector <ll> m;
bool viv=false;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
ll mini=inf;
for (i=0; i<k; i++)
  {
  ll a,b;
  cin>>a>>b;
  mini=min(mini, b-a+1);
  }
cout<<mini<<endl;
for (i=0; i<n; i++)
  cout<<(i%mini)<<' ';


    return 0;
}