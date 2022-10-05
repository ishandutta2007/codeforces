#include <bits/stdc++.h>

using namespace std;

long n,k,i,j;
vector <long> m;
long gr[200000],st[200000];
int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  long a; cin>>a; m.push_back(a);
  if (k==1)
    cout<<a<<' ';
  }
if (k==1)
  return 0;

for (i=0; i<=256; i++)
  gr[i]=-1;

long cc=0;
for (long i1=0; i1<n; i1++)
  {
  i=m[i1];
  j=i;
  for (long j1=i; j1>max((long)0, i-k+1);  j1--)
    if (gr[j1]==-1)
      j=j1;
    else
      j1=-1;
  if (gr[j]==-1)
    j--;
  j=max((long)0, j);
 // cout<<"Ok "<<i1<<" is "<<j<<endl;

  if (gr[j]!=-1&&(i-st[j]+1<=k))
    {
   // cout<<"was "<<i1<<' '<<st[j]<<endl;
    long rs=st[j];
    for (long u=rs; u<=i; u++)
      {
      gr[u]=gr[rs];
      st[u]=rs;
      }
    cout<<rs<<' ';
    }
  else
    {
    long rs=j;
    if (gr[rs]!=-1)
      rs++;
    gr[rs]=cc;
    cc++;
    for (long u=rs; u<=i; u++)
      {
      gr[u]=gr[rs];
      st[u]=rs;
      }
    cout<<rs<<' ';
    }
  }

         /*
cout<<endl;
for (i=0; i<20; i++)
  cout<<gr[i]<<' ';
cout<<endl;
for (i=0; i<20; i++)
  cout<<st[i]<<' ';
//   */
    return 0;
}