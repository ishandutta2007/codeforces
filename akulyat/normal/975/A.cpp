#include <bits/stdc++.h>

using namespace std;

long n,i,j;
string s;
vector <string> sl;
string norm(string s)
{
long l=s.size();
string ns="";
for (long i=0; i<l; i++)
  {
  bool ost=true;
  for (long j=0; j<i; j++)
    if (s[i]==s[j])
      ost=false;
  if (ost)
    ns+=s[i];
  }
l=ns.size();
for (long i=0; i<l; i++)
  for (long j=0; j<l-1; j++)
    if (ns[j]>ns[j+1])
      {
      char c=ns[j];
      ns[j]=ns[j+1];
      ns[j+1]=c;
      }
return ns;
}

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  sl.push_back(s);
  }

for (i=0; i<n; i++)
  sl[i]=norm(sl[i]);

long ans=0;
for (i=0; i<n; i++)
  {
  bool un=true;
  for (j=0; j<i; j++)
    if (sl[j]==sl[i])
      un=false;
  if (un)
    ans++;
  }
cout<<ans;


    return 0;
}