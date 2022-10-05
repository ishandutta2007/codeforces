#include <bits/stdc++.h>

using namespace std;

long n,i,j;
string s[1000];
vector <string> ss;


bool ps (string a, string b, bool c)
{
long l1=a.size();
long l2=b.size();
if (c)
  if (l1<l2)
    swap(a, b);
l1=a.size();
l2=b.size();
//cout<<"Here "<<a<<' '<<b<<endl;
bool good=false;
for (long i=0; i<=(l1-l2); i++)
  {
  if (b==a.substr(i, l2))
    good=true;
//  cout<<"Watch "<<b<<' '<<a.substr(i, l2)<<endl;
  }
return good;
}

void sw(long a, long b)
{
string ss;
ss=s[a];
s[a]=s[b];
s[b]=ss;
}

int main()
{
cin>>n;
for (i=0; i<n; i++)
  cin>>s[i];

for (i=0; i<n; i++)
  for (j=i+1; j<n; j++)
    if (!ps(s[i], s[j], true))
      {
      cout<<"NO"<<endl;
//      cout<<i<<' '<<j<<endl;
      return 0;
      }
cout<<"YES"<<endl;

for (i=1; i<n; i++)
  {
  j=i;
  while (j>0&&ps(s[j], s[j-1], false))
    {
    sw(j, j-1);
    j--;
    }
  }

for (i=0; i<n; i++)
  ss.push_back(s[i]);
reverse(ss.begin(), ss.end());

for (i=0; i<n; i++)
  cout<<ss[i]<<endl;



    return 0;
}