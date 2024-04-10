#include <bits/stdc++.h>

using namespace std;

long long n,i;
vector <long long> m,v;
vector < pair <long long, long long> >  m1;
vector <long long> k[400000];
long long will[400000];

int main()
{
cin>>n;

for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back(a); m1.push_back({a, i}); }

sort(m1.begin(), m1.end());

long long j=0;
k[0].push_back(m1[0].second);
v.push_back(m1[0].first);

/*
for (i=0; i<n; i++)
  cout<<'{'<<m1[i].first<<' '<<m1[i].second<<'}';
cout<<endl;
*/

for (i=1; i<n; i++)
  {
  if (m1[i].first!=m1[i-1].first)
    {
    j++;
    v.push_back(m1[i].first);
    }
  k[j].push_back(m1[i].second);
  }

/*
for (i=0; i<v.size(); i++)
  cout<<v[i]<<' ';
cout<<endl;

for (i=0; i<v.size(); i++)
  {
  for (long long j=0; j<k[i].size(); j++)
    cout<<k[i][j]<<' ';
  cout<<endl;
  }
*/

vector <bool> use;
for (i=0; i<v.size(); i++)
  use.push_back(true);

for (i=0; i<v.size(); i++)
  if (use[i])
  {
  sort(k[i].begin(), k[i].end());
  reverse(k[i].begin(), k[i].end());
  long long z=2*v[i];
  long long w=lower_bound(v.begin(), v.end(), z)-v.begin();
    {
    long long vv=v[i];
    vector <long long> h;
    h=k[i];
    while (h.size()>0)
      {
      long long ww=lower_bound(v.begin(), v.end(), vv)-v.begin();
      if (ww!=v.size()&&v[ww]==vv&&ww>i)
        {
        use[ww]=false;
        long long cl=k[ww].size();
        for (long long q=0; q<cl; q++)
          h.push_back(k[ww][q]);
        }
      sort(h.rbegin(), h.rend());
      vector <long long> h1;
      for (long long q=h.size()-1; q>=0; q--)
        if ((q^h.size()^1)&1)
          h1.push_back(h[q]);
      reverse(h1.begin(), h1.end());
      if (h.size()&1)
        will[h[0]]=vv;
      h=h1;
      vv*=2;
      }
    }
  }

long long kol=0;
for (i=0; i<n; i++)
  if (will[i]!=0)
    kol++;

cout<<kol<<endl;
for (i=0; i<n; i++)
  if (will[i]!=0)
    cout<<will[i]<<' ';
cout<<endl;

    return 0;
}