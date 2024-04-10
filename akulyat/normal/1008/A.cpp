#include <iostream>

using namespace std;

long long n,i;
string s;

bool sogl(char s)
{
if (s=='a') return false;
if (s=='o') return false;
if (s=='u') return false;
if (s=='i') return false;
if (s=='e') return false;

return true;
}

int main()
{
cin>>s;
s+='d';
n=s.size();
for (i=0; i<n-1; i++)
  {
  if (sogl(s[i])&&sogl(s[i+1])&&s[i]!='n')
    {
    cout<<"NO";
    return 0;
    }
  }

cout<<"YES"<<endl;


    return 0;
}