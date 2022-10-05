#include <bits/stdc++.h>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long pp,i,j,u,n,m;
string ip[2300], d[2300];
string s;


cin>>n>>m;
getline(cin, s);
for (i=0; i<n; i++)
  {
  string s;
  getline(cin, s);
  for (j=0; j<s.size(); j++)
    if (s[j]==' ')
      pp=j;
  d[i]="";
  for (j=0; j<pp; j++)
    d[i]+=s[j];
  ip[i]="";
  for (j=pp+1; j<s.size(); j++)
    ip[i]+=s[j];
//  cout<<"good"<<endl;
  }



for (i=n; i<n+m; i++)
  {
  string s;
  getline(cin, s);
  for (j=0; j<s.size(); j++)
    if (s[j]==' ')
      pp=j;
  d[i]="";
  for (j=0; j<pp; j++)
    d[i]+=s[j];
  ip[i]="";
  for (j=pp+1; j<s.size()-1; j++)
    ip[i]+=s[j];

      for (u=0; u<n; u++)
        if (ip[u]==ip[i])
          cout<<s<<' '<<'#'<<d[u]<<endl;
  }
//for (i=0; i<n+m; i++)
//  {
//  cout<<i<<endl;
//  cout<<d[i]<<endl;
//  cout<<ip[i]<<endl;
//  }
   return 0;
}