#include <bits/stdc++.h>

using namespace std;

vector < pair< long long, long> > m;
vector <long> wp;
string s;

long i,j,n;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long a; cin>>a; m.push_back({a, i});
  }
getline(cin, s);
getline(cin, s);
sort(m.rbegin(), m.rend());

long k=n-1;
long l=-1;

for (long u=0; u<2*n; u++)
  {
  long t;
  t=s[u]-'0';
  if (t==0)
    {
    wp.push_back(m[k].second);
    cout<<m[k].second+1<<' ';
    k--;
    }
  if (t==1)
    {
    cout<<wp.back()+1<<' ';
    wp.pop_back();
    }
//  cout<<i<<' '<<"Ok"<<endl;
  }

    return 0;
}