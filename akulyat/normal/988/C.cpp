#include <bits/stdc++.h>

using namespace std;

long long k,i,j;
vector <long> n,s;
vector <long> m[300000];
vector <pair <long, pair<long, long> > > v;

int main()
{
cin>>k;
for (i=0; i<k; i++)
  {
  long l;
  cin>>l;
  n.push_back(l);
  s.push_back(0);
  for (j=0; j<n[i]; j++)
  {long a; cin>>a; m[i].push_back(a); s.back()+=a; }
  for (j=0; j<n[i]; j++)
    v.push_back({s.back()-m[i][j], {i, j}});
  }

sort(v.begin(), v.end());

for (i=1; i<v.size(); i++)
  {
  if (v[i].first==v[i-1].first&&(v[i].second.first!=v[i-1].second.first))
    {
    cout<<"YES"<<endl;
    cout<<v[i].second.first+1<<' '<<v[i].second.second+1<<endl;
    cout<<v[i-1].second.first+1<<' '<<v[i-1].second.second+1<<endl;
    return 0;
    }
  }
cout<<"NO"<<endl;

    return 0;
}