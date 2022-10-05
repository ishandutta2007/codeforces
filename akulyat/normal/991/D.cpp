#include <bits/stdc++.h>

using namespace std;

long long n,i;
string s1,s2;
long long ans[10000][4];

int main()
{
cin>>s1>>s2;
n=s1.size();
s1+="00";
s2+="00";
for (i=0; i<n-1; i++)
  {
  ans[i+1][1]=ans[i][0];
  ans[i+1][2]=ans[i][0];
  if (s1[i+1]=='0'&&s1[i]=='0'&&s2[i]=='0')
    ans[i+1][1]=max(ans[i+1][1], ans[i-1][0]+1);
  if (s2[i+1]=='0'&&s1[i]=='0'&&s2[i]=='0')
    ans[i+1][2]=max(ans[i+1][2], ans[i-1][0]+1);

  ans[i+1][0]=max(ans[i+1][1], ans[i+1][2]);
  if (s2[i+1]=='0'&&s1[i+1]=='0'&&s1[i]=='0')
    ans[i+1][0]=max(ans[i+1][0], ans[i][2]+1);
  if (s2[i+1]=='0'&&s1[i+1]=='0'&&s2[i]=='0')
    ans[i+1][0]=max(ans[i+1][0], ans[i][1]+1);
  }

 /*
for (i=0; i<=n; i++)
  cout<<ans[i][0]<<' ';
cout<<endl;
for (i=0; i<=n; i++)
  cout<<ans[i][1]<<' ';
cout<<endl;
for (i=0; i<=n; i++)
  cout<<ans[i][2]<<' ';
cout<<endl;
// */
cout<<ans[n-1][0];

    return 0;
}