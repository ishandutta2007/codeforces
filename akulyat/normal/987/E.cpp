#include <bits/stdc++.h>

using namespace std;


long n,i;
vector <long> m;
long col[2*1000*1000];

int main()
{
ios::sync_with_stdio(0);cin.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {long a; cin>>a; a--; m.push_back(a);}
long tc=0;
for (i=0; i<n; i++)
  if (col[i]==0)
  {
  tc++;
  long v=i;
  while (col[v]==0)
  {col[v]=tc; v=m[v];}
  }
tc%=2;
if (tc==1)
  cout<<"Um_nik";
else
  cout<<"Petr";
    return 0;
}