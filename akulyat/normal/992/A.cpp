#include <bits/stdc++.h>

using namespace std;


long long n,i;
set <long long> s;
int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  if (a!=0)
    s.insert(a);
  }

cout<<s.size();

    return 0;
}