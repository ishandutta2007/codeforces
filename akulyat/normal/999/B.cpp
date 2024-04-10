#include <bits/stdc++.h>

using namespace std;

long long n,i,j,u;
string s;


int main()
{

cin>>n>>s;
for (i=1; i<=n; i++)
  if (n%i==0)
    {
    long p=0;
    string s2;
    for (j=0; j<n/i; j++)
      {
      string s1;
      for (u=0; u<i; u++)
        {
        s1+=s[p];
        p++;
        }
      if (j==0)
        reverse(s1.begin(), s1.end());
      s2+=s1;
      }
    s=s2;
//    cout<<s<<endl;
    }

cout<<s;



    return 0;
}