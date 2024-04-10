#include <bits/stdc++.h>

using namespace std;

struct block
{
  long z,p;
};

const long long k=1000;
const long long ml=k*k;
long long x1,x2,n,i,j;
vector <block> m;
vector <long long> t1,t2;


bool cmp(block a, block b)
{
if (a.z<b.z)
  return true;
if (a.z==b.z&&a.p<b.p)
  return true;
return false;
}

long long need(long long a, long long b)
{
if (a%b!=0)
  {
  a-=(a%b);
  a+=b;
  }
return a/b;
}

int main()
{
cin>>n>>x1>>x2;

for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back({a, i});}
sort(m.begin(), m.end(), cmp);

for (i=0; i<n; i++)
  {
  long long v=m[i].z;
  long long k=need(x1, v);
  if (i+k-1<n)
    t1.push_back(i+k-1);
  else
    t1.push_back(n);
  }
t1.push_back(n);

for (i=0; i<n; i++)
  {
  long long v=m[i].z;
  long long k=need(x2, v);
  if (i+k-1<n)
    t2.push_back(i+k-1);
  else
    t2.push_back(n);
  }
t2.push_back(n);


for (i=0; i<n; i++)
  {
  long long a1=i;
  long long a2=t1[i];
  if (a2<n)
    {
    long long a3=t2[a2+1];
    if (a3<n)
      {
      cout<<"Yes"<<endl;
      cout<<a2-a1+1<<' '<<a3-a2<<endl;
      for (long j=a1; j<=a2; j++)
        cout<<m[j].p+1<<' ';
      cout<<endl;
      for (long j=a2+1; j<=a3; j++)
        cout<<m[j].p+1<<' ';
      cout<<endl;
      return 0;
      }
    }
  }

for (i=0; i<n; i++)
  {
  long long a1=i;
  long long a2=t2[i];
  if (a2<n)
    {
    long long a3=t1[a2+1];
    if (a3<n)
      {
      cout<<"Yes"<<endl;
      cout<<a3-a2<<' '<<a2-a1+1<<endl;

      for (long j=a2+1; j<=a3; j++)
        cout<<m[j].p+1<<' ';
      cout<<endl;

      for (long j=a1; j<=a2; j++)
        cout<<m[j].p+1<<' ';
      cout<<endl;
      return 0;
      }
    }
  }

cout<<"No"<<endl;

    return 0;
}