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
vector <ll> m;
bool viv=false;

void bad()
{
cout<<"OVERFLOW!!!";
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
ll big=(1LL<<32)-1;


vector <ll> val;
val.push_back(0);
vector <ll> f;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  if (s=="add")
    val.back()++;
  if (s=="end")
    {
    ll res=val.back();
    val.pop_back();
    val.back()+=f.back()*res;
    f.pop_back();
    }
  if (s=="for")
    {
    ll k;
    cin>>k;
    f.push_back(k);
    val.push_back(0);
    }
  if (val.back()>big)
    bad();
  }
cout<<val.back()<<endl;

    return 0;
}
/**
6
for 2
  for 62
    add
    add
  end
end





**/