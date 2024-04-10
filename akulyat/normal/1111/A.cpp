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
vector <bool> v;
bool viv=false;
string s,t;

void bad()
{
cout<<"No";
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
v.assign(26, false);
v['a'-'a']=true;
v['e'-'a']=true;
v['i'-'a']=true;
v['o'-'a']=true;
v['u'-'a']=true;
cin>>s>>t;
n=s.size();
if (t.size()!=n)
  bad();
for (i=0; i<n; i++)
  if (v[s[i]-'a']!=v[t[i]-'a'])
    bad();
cout<<"Yes"<<endl;



    return 0;
}