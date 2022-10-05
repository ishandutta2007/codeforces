#include <bits/stdc++.h>

using namespace std;

vector <long long> m, ans;
long n,i,s;

int main()
{
cin>>n;
for (i=0; i<n-1; i++)
  {
  cout<<"? "<<i+1<<' '<<i+2<<endl;
//  flush(stdout);
  long a;
  cin>>a;
  m.push_back(a);
  }

cout<<"? "<<1<<' '<<3<<endl;
//flush(stdout);
long a;
cin>>a;
m.push_back(a);

s=(m[0]+m[1]-m[n-1])/2;
ans.push_back(m[0]-s);
ans.push_back(s);

for (i=1; i<n-1; i++)
  ans.push_back(m[i]-ans.back());

cout<<"! ";
for (i=0; i<n; i++)
  cout<<ans[i]<<' ';
    return 0;
}