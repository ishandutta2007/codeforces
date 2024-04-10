#include <bits/stdc++.h>

using namespace std;

long long n,i,j;
vector <long long> m;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back(a); }

sort(m.begin(),  m.end()  );


vector <long long> ans;
ans.push_back(m[0]);

for (i=0; i<n; i++)
  {
  long long v=m[i];
  long long z=1;
  for (long u=0; u<32; u++)
    {
    vector <long long > lans;
    lans.push_back(v);
    long long a=v-z;
    long long b=v+z;
    long long a1=lower_bound(m.begin(), m.end(), a)-m.begin();
    long long b1=lower_bound(m.begin(), m.end(), b)-m.begin();
    if (a==m[a1])
      lans.push_back(a);
    if (b==m[b1])
      lans.push_back(b);
    if (lans.size()>ans.size())
      ans=lans;
    z*=2;
    }
  }

cout<<ans.size()<<endl;

for (i=0; i<ans.size(); i++)
  cout<<ans[i]<<' ';


    return 0;
}