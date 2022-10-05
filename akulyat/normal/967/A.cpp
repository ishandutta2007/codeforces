#include <bits/stdc++.h>

using namespace std;

long  long n,s,i;
vector <pair <long long, long long> > m;


int main()
{
cin>>n>>s;
s++;
for (i=0; i<n; i++)
  {
  long long a,b;
  cin>>a>>b;
  m.push_back({a,b});
  }
m.push_back({0, -s});
sort(m.begin(), m.end());
m.push_back({200, 0});
n+=2;

for (i=0; i<n-1; i++)
  {
  long long h=m[i].first;
  long long mi=m[i].second;
  mi+=s;
  h+=mi/60;
  mi%=60;

  long long h2=h;
  long long mi2=mi;
  mi2+=s;
  h2+=mi2/60;
  mi2%=60;
  if (h2<m[i+1].first||(h2==m[i+1].first&&mi2<=m[i+1].second))
    {
    cout<<h<<' '<<mi<<endl;
    return 0;
    }

  }


    return 0;
}