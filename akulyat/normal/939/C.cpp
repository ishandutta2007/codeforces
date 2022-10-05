#include <bits/stdc++.h>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long n,i,j,kol=0,ans;
vector <long> par;
cin>>n;
for (i=0; i<n; i++)
  {
  long a;
  cin>>a;
  par.push_back(a);
  }
long a,b;
cin>>a>>b;
long c=b-a;
for (i=0; i<c; i++)
  {
  kol+=par[i];
  }
ans=kol;
long ti=a;
long bt=a;
//cout<<kol<<endl;
for (j=0; j<n; j++)
  {
  ti--;
  if (ti<=0)
    ti+=n;
  kol-=par[j];
  kol+=par[(j+c)%n];
  //cout<<kol<<' '<<ti <<' '<<j<<endl;
  if (kol>=ans)
    {
    if (kol==ans)
      bt=min(ti, bt);
      else bt=ti;
    ans=kol;
    }
  }
cout<<bt;



    return 0;
}