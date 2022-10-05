#include <iostream>

using namespace std;

long n,i;
string s;

int main()
{
cin>>n;
getline(cin, s);
getline(cin, s);
s='0'+s;
s=s+'0';
n++;
n++;

bool good=true;

for (i=0; i<n-1; i++)
  if (s[i]=='1'&&s[i+1]=='1')
    good=false;
for (i=0; i<n-2; i++)
  if (s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='0')
    good=false;

if (good)
  cout<<"Yes";
else
  cout<<"No";

    return 0;
}