#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;

long n,i,j;
vector <long long> m,w,w2;
long ans[200*kk];
string s[200*kk];


int main()
{
for (i=0; i<6; i++)
  {long a; cin>>a; m.push_back(a); }
for (i=0; i<7; i++)
  w.push_back(0);
for (i=0; i<7; i++)
  w2.push_back(0);

cin>>n;
for (i=0; i<n; i++)
  {
  cin>>s[i];
  long l=s[i].size();
  long rl=l;
  long p=l;
  for (long j=0; j<l; j++)
    if (s[i][j]==',')
      {
      p=j;
      }
  l=p;
  string rs="";
  for (long j=0; j<l; j++)
    rs+=s[i][j];
  if (rs=="S"&&l==rl)
    {
    m[0]--;
    ans[i]=0;
    }
  if (rs=="M"&&l==rl)
    {
    m[1]--;
    ans[i]=1;
    }
  if (rs=="L"&&l==rl)
    {
    m[2]--;
    ans[i]=2;
    }
  if (rs=="XL"&&l==rl)
    {
    m[3]--;
    ans[i]=3;
    }
  if (rs=="XXL"&&l==rl)
    {
    m[4]--;
    ans[i]=4;
    }
  if (rs=="XXXL"&&l==rl)
    {
    m[5]--;
    ans[i]=5;
    }






  if (rs=="S"&&l!=rl)
    {
    w[0]++;
    ans[i]=6+0;
    }
  if (rs=="M"&&l!=rl)
    {
    w[1]++;
    ans[i]=6+1;
    }
  if (rs=="L"&&l!=rl)
    {
    w[2]++;
    ans[i]=6+2;
    }
  if (rs=="XL"&&l!=rl)
    {
    w[3]++;
    ans[i]=6+3;
    }
  if (rs=="XXL"&&l!=rl)
    {
    w[4]++;
    ans[i]=6+4;
    }
  }

for (i=0; i<6; i++)
  {
  if (m[i]<0)
    {
    cout<<"NO"<<endl;
    return 0;
    }
  }

for (i=0; i<6; i++)
  {
  long long per=w2[i]+w[i]-m[i];
  per=max((long long)0, per);
  w[i]-=per;
  w2[i+1]+=per;
  }
for (i=0; i<6; i++)
  if (w[i]<0)
    {
    cout<<"NO"<<endl;
    return 0;
    }
for (i=0; i<6; i++)
  w[i]+=w2[i];
cout<<"YES"<<endl;

for (long p=6; p<12; p++)
  {
  for (i=0; i<n; i++)
    if (ans[i]==p)
      {
      if (w[p-6]>0)
        {
        ans[i]=p-6;
        w[p-6]--;
        }
      else
        {
        ans[i]=p-5;
        w[p-5]--;
        }
      }
  }
/*
for (i=0; i<n; i++)
  cout<<ans[i]<<' ';
cout<<endl;
*/
for (i=0; i<n; i++)
  {
  if (ans[i]==0)
    cout<<"S"<<endl;
  if (ans[i]==1)
    cout<<"M"<<endl;
  if (ans[i]==2)
    cout<<"L"<<endl;
  if (ans[i]==3)
    cout<<"XL"<<endl;
  if (ans[i]==4)
    cout<<"XXL"<<endl;
  if (ans[i]==5)
    cout<<"XXXL"<<endl;
  if (ans[i]<0||ans[i]>5)
    cout<<"Soryan"<<endl;
  }




    return 0;
}