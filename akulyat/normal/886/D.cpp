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
vector <string> m;
bool viv=false;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
vector <bool> nal(26, false);
for (i=0; i<n; i++)
  {
  string a;
  cin>>a;
  for (auto s:a)
    nal[s-'a']=true;
  m.push_back(a);
  }


for (i=0; i<n; i++)
  {
  vector <bool> b(26, false);
  for (auto sy:m[i])
    {
    if (b[sy-'a'])
      {
      cout<<"NO"<<endl;
      return 0;
      }
    b[sy-'a']=true;
    }
  }
map <char, set<ll> > aft;
map <char, set<ll> > bef;

for (i=0; i<n; i++)
  {
  string s=m[i];
  ll l=s.size();
  for (j=1; j<l; j++)
    {
    bef[s[j]-'a'].insert(s[j-1]-'a');
    aft[s[j-1]-'a'].insert(s[j]-'a');
    }
  }

for (auto b=0; b<26; b++)
  if (aft[b].size()>1||bef[b].size()>1)
    {
    cout<<"NO"<<endl;
    return 0;
    }

vector <string> part;
vector <ll> col(26, -1);
for (i=0; i<26; i++)
  if (col[i]==-1&&nal[i]&&bef[i].size()==0)
    {
    string s;
    ll ch=i;
    s+=char('a'+i);
    while (aft[ch].size()!=0)
      {
      s+=char('a'+*aft[ch].begin());
      ch=*aft[ch].begin();
      }
    part.push_back(s);
    }
//for (auto s:part)
//  cout<<s<<endl;

sort(part.begin(), part.end());
ll kol=0;
for (auto i:nal)
  if (i)
    kol++;

string ans;
for (auto i:part)
  ans+=i;
if (ans.size()==kol)
  {
  cout<<ans<<endl;
  return 0;
  }
//cout<<kol<<' '<<ans.size()<<' '<<ans<<endl;
cout<<"NO"<<endl;


    return 0;
}