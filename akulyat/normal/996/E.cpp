#include <bits/stdc++.h>

using namespace std;

const long long maxl=1500000;
const long long con=maxl*maxl;
long long n,i;
vector <pair <long long, long long> > m;
long long wr[1000000];
long long l(long long x, long long y)
{
return x*x+y*y;
}

int main()
{
srand(time(0));
cin>>n;
for (i=0; i<n; i++)
  {
  long long a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }


for (long long u=0; u<50; u++)
  {
  vector <pair <long long, long long> > tor;
  vector <long long> st,ans;
  for (i=0; i<n; i++)
    {
    tor.push_back({rand()%100000, i});
    }
  sort(tor.begin(), tor.end());
  for (i=0; i<n; i++)
    st.push_back(tor[i].second);
  long long x=0, y=0;
  for (i=0; i<n; i++)
    {
    long long v=st[i];
    if (l(x+m[v].first, y+m[v].second)<=l(x-m[v].first, y-m[v].second))
      {
      ans.push_back(1);
      x+=m[v].first;
      y+=m[v].second;
      }
    else
      {
      ans.push_back(-1);
      x-=m[v].first;
      y-=m[v].second;
      }
    }
  if (l(x, y)<=con)
    {
    for (i=0; i<n; i++)
      wr[st[i]]=ans[i];
    for (i=0; i<n; i++)
      cout<<wr[i]<<' ';
    return 0;
    }
  }



    return 0;
}