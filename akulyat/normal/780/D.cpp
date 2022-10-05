#include <iostream>

using namespace std;

const long k=1000;
long n,i,j;
string s0[2*k];
string s1[2*k];
bool can[2*k][2];
bool comp[2*k];
long m0[2*k],m1[2*k];
long used[100*k];

int main()
{

{//Reading
cin>>n;
for (i=0; i<n; i++)
  for (j=0; j<2; j++)
    can[i][j]=true;
for (i=0; i<n; i++)
  {
  string n1,n2;
  cin>>n1;
  cin>>n2;
  s0[i]=n1.substr(0, 3);
  s1[i]=n1.substr(0, 2)+n2.substr(0, 1);
  }
for (i=0; i<n; i++)
  {
  m0[i]=26*26*(s0[i][0]-'A')+26*(s0[i][1]-'A')+(s0[i][2]-'A');
  m1[i]=26*26*(s1[i][0]-'A')+26*(s1[i][1]-'A')+(s1[i][2]-'A');
  }
}


for (i=0; i<n; i++)
  for (j=i+1; j<n; j++)
    if (m0[i]==m0[j])
      {
      can[i][0]=false;
      can[j][0]=false;
      }
long good=0;

while (good!=n)
  {
  long add=0;
  for (i=0; i<n; i++)
    {
    if (!can[i][0]&&!can[i][1])
      {
   //   cout<<good<<' '<<i<<' '<<0<<endl;
      cout<<"NO"<<endl;
      return 0;
      }
    if (can[i][0]&&!can[i][1]&&!comp[i])
      {
      if (used[m0[i]]!=0)
        {
    //    cout<<good<<' '<<i<<' '<<1<<endl;
        cout<<"NO"<<endl;
        return 0;
        }
      used[m0[i]]=1;
    //  cout<<"Ok, let use "<<'"'<<s0[i]<<'"'<<" u "<<i<<endl;
      comp[i]=true;
      add++;
      }
    if (!can[i][0]&&can[i][1]&&!comp[i])
      {
      if (used[m1[i]]!=0)
        {
    //    cout<<good<<' '<<i<<' '<<2<<endl;
        cout<<"NO"<<endl;
        return 0;
        }
      used[m1[i]]=1;
    //  cout<<"Ok, let use "<<'"'<<s1[i]<<'"'<<" u "<<i<<endl;
      comp[i]=true;
      add++;
      }
    }
  for (i=0; i<n; i++)
    if (can[i][0]&&used[m0[i]]!=0&&!comp[i])
      can[i][0]=false;
  for (i=0; i<n; i++)
    if (can[i][1]&&used[m1[i]]!=0&&!comp[i])
      can[i][1]=false;
  if (add==0)
    {
    for (i=0; i<n; i++)
      if (!comp[i])
        {
        can[i][1]=false;
        comp[i]=true;
        add++;
        }
    }
  good+=add;
  }


for (i=0; i<n; i++)
  if (!can[i][0]&&!can[i][1])
    {
    cout<<"NO"<<endl;
    return 0;
    }


cout<<"YES"<<endl;
for (i=0; i<n; i++)
  {
  if (can[i][0])
    cout<<s0[i]<<endl;
  else
    cout<<s1[i]<<endl;
  }

    return 0;
}