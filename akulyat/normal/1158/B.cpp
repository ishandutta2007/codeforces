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


ll n,i,j,k, ost;
vector <ll> m;
bool viv=false;

ll check(string s)
{
ll n=s.size();
set <pair <ll, string> > st;
multiset <string> ms;
for (ll i=0; i<n; i++)
  {
  string ss="";
  for (ll j=i; j<n; j++)
    {
    ss+=s[j];
    st.insert({ss.size(), ss});
    ms.insert(ss);
    }
  }
for (auto pr:st)
  if (ms.count(pr.S)==1)
    return pr.F;
}

void solve(ll n, ll k)
{
ll pl=n/2;
pl-=k/2;
pl++;
string ans;
while (ans.size()!=n)
  ans+='1';
//cout<<"For "<<n<<' '<<k<<" use "<<pl<<endl;
for (ll i=pl-1; i<n; i+=pl)
  ans[i]='0';
if (viv)
  cout<<n<<' '<<k<<' ';
if (false&&check(ans)!=k)
  {
  if (viv)
    cout<<"Bad: ";
  cout<<ans<<endl;
  return;
  }
if (viv)
  cout<<"Good!!!!!!!!"<<endl;
//if (!viv)
  cout<<ans<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
if (viv)
  for (ll i=1; i<50; i++)
    {
    for (ll j=i; j>0; j-=2)
      solve(i, j);
    }
cin>>n>>k;
solve(n, k);










    return 0;
}
/**
01010
0010100
1011011
1110111

11111111111110
11111111111100
11100011100

-2 -3
010101010
101101 10 110




1 1 1

2 2 10

3 1 101
3 3 111

5 1 11011
5 3 10101
5 5 11111

7 1 1110111
7 3 1101101
7 5 1010101
7 7 0000000

9 1 111101111
9 3 111011011
9 5 110110110
9 7 101010101
9 9 000000000

11 1 11111011111
11 3 11110111101
11 5 11101110111
11 7 11011011011
11 9
11 11

11

7/3 2 2 3

**/