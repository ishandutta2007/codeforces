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
vector <ll> p;
vector <bool> pr;
ll kol[3];

vector <long long> erat(long long last)
{
vector <bool> bad;
vector <long long> r;
for (long long i=0; i<last+10; i++)
  bad.push_back(true);
for (long long i=2; i<=last; i++)
  if (bad[i])
    {
    long long j=2;
    while (j*i<=last)
      {
      bad[j*i]=false;
      j++;
      }
    r.push_back(i);
    }
return r;
}

void work()
{
ll cur=kol[1]+kol[2]+kol[2];
vector <ll> ans;
while (cur>0)
  {
  ll use=1;
  if (kol[2]&&!pr[cur-1])
    use=2;
  if (!kol[use])
    use=3-use;
  kol[use]--;
  ans.push_back(use);
  cur-=use;
  }
reverse(ans.begin(), ans.end());
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  kol[a]++;
  }
p=erat(ml);
pr.resize(ml+3, false);
for (auto i:p)
  pr[i]=true;
work();






    return 0;
}