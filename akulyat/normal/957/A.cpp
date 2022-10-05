#include <iostream>

using namespace std;

bool can;
long n,i;
string s;

int main()
{
cin>>n;
can=false;
getline(cin, s);
getline(cin, s);
n=0;
for (i=0; i<s.size(); i++)
  if (s[i]!=' ')
    n++;
for (i=0; i<n-1; i++)
  {
  if ((s[i]==s[i+1])&&(s[i]!='?'))
    {
    cout<<"No";
    return 0;
    }
  }
//cout<<"acs"<<endl;
for (i=1; i<n; i++)
  {
//  cout<<(s[i]==s[i+1]);
  if (s[i]==s[i+1])
    can=true;
  }
for (i=0; i<n; i++)
  if ((s[i]=='?'))
    if ((i==0)||(i==n-1)||(s[i-1]==s[i+1]))
      can=true;

if (can)
  {
  cout<<"Yes";
  return 0;
  }
cout<<"No";

    return 0;
}