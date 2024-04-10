#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,k;
vector <ll> m;
set <char> st;
string s,ans;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k>>s;
for (i=0; i<n; i++)
  st.insert(s[i]);

if (k>n)
  {
  ans=s;
  while (n<k)
    {
    ans+=*st.begin();
    n++;
    }
  cout<<ans;
  return 0;
  }

ans=s.substr(0, k);
//cout<<ans<<endl;

char big=*st.rbegin();
//cout<<big<<' '<<ans.back()<<endl;
while(ans.size()>0&&ans.back()==big)
  ans.pop_back();
//cout<<ans<<endl;

char buk=ans.back();
buk++;
while (st.find(buk)==st.end())
  buk++;
ans.back()=buk;
while (ans.size()<k)
  ans+=*st.begin();

cout<<ans;



    return 0;
}