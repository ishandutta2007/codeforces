#include <bits/stdc++.h>

using namespace std;

long n,i,j,x=-1,y=-1;
vector <long long> m;
int main()


{
cin>>n;
for (i=0; i<n; i++)
  {
  long a; cin>>a; m.push_back(a);
  }

for (i=0; i<n-1; i++)
  {
  if (abs(m[i]-m[i+1])!=1)
    {
    if ((y!=-1&&(y!=abs(m[i]-m[i+1])))||(m[i]==m[i+1]))
      {
      cout<<"NO";
      return 0;
      }
    y=abs(m[i]-m[i+1]);
    }
  }
if (y==-1)
  {
  cout<<"YES"<<endl;
  cout<<"1000000000 1";
  return 0;
  }

for (i=0; i<n-1; i++)
  {
  if ((m[i]==m[i+1]+1&&m[i]%y==1&&m[i+1]%y==0)||(m[i]+1==m[i+1]&&m[i]%y==0&&m[i+1]%y==1))
    {
    cout<<"NO";
    return  0;
    }
  }
cout<<"YES"<<endl;
cout<<1000000000<<' '<<y<<endl;


    return 0;
}