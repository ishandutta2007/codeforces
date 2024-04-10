#include <bits/stdc++.h>

using namespace std;

long long n,i,sum,cur;
vector <long long> m;


int main()
{
cin>>n;
for (i=0; i<n; i++)
{
long a; cin>>a; m.push_back(a);
sum+=a;
}

for (i=0; i<n; i++)
  {
  cur+=m[i];
  if (2*cur>=sum)
    {
    cout<<i+1<<endl;
    return 0;
    }
  }


    return 0;
}