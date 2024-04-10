#include <bits/stdc++.h>

using namespace std;

long long n,i,x,y,j,kol;
vector <long long> m;
string s;

int main()
{
cin>>n>>x>>y>>s;
for (i=0; i<n; i++)
  {
  long long a;
  a=s[i]-'0';
  m.push_back(a);
  }
m.push_back(1);
for (i=0; i<n; i++)
  if (m[i]==0&&m[i+1]==1)
    kol++;


long long ans=min(y*kol, (kol-1)*x+y);
ans=max(ans, (long long)0);

cout<<ans;



    return 0;
}