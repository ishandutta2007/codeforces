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


ll n,i,j;
vector <ll> m[2];
bool viv=false;

void good()
{
cout<<"YES"<<endl;
exit(0);
}

int main()
{
ll s;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>s;
s--;
for (j=0; j<2; j++)
  for (i=0; i<n; i++)
    {
    ll a;
    cin>>a;
    m[j].push_back(a);
    }
  if (m[0][0]&&m[0][s])
    good();

for (i=0; i<n; i++)
  if (i>=s)
  if (m[0][0]&&m[1][s]&&m[0][i]&&m[1][i])
    good();
cout<<"NO"<<endl;



    return 0;
}