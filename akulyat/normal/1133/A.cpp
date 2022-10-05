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
string s, t;
bool viv=false;

string str(ll v)
{
string ans;
while (v)
  ans+=char(v%10+'0'), v/=10;
while (ans.size()<2)
  ans+='0';
reverse(ans.begin(), ans.end());
return ans;
}

ll dif(string a, string b)
{
ll ans=0;
ans+=(b[4]-a[4])*1;
ans+=(b[3]-a[3])*10;
ans+=(b[1]-a[1])*60;
ans+=(b[0]-a[0])*600;
return ans;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s>>t;
for (ll h=0; h<24; h++)
  for (ll m=0; m<60; m++)
    {
    string mi=str(h)+':'+str(m);
//    cout<<mi<<' '<<dif(s, mi)<<' '<<dif(mi, t)<<endl;

    if (dif(s, mi)==dif(mi, t))
      {
      cout<<mi<<endl;
      exit(0);
      }
    }

    return 0;
}