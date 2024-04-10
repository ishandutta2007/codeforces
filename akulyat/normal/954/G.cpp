#include <bits/stdc++.h>

using namespace std;

long long n,r,k,i;
vector <long long> m,st,pref;
long long sum=0;
long long add,ost;

void work(long long num, long long mini)
{
long long need=mini-m[i];
sum-=st[num%(2*r+1)];


st[num%(2*r+1)]=0;
need-=sum;

if (need>0)
  {
  st[num%(2*r+1)]=need;
  sum+=need;
  ost-=need;
  }
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>r>>k;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }

pref.push_back(0);
for (i=0; i<n; i++)
  pref.push_back(pref.back()+m[i]);

for (i=0; i<n; i++)
  {
  long long a=i-r;
  long long b=i+r;
  a=max((long long)0, a);
  b=min((long long)n-1, b);
  b++;
  m[i]=pref[b]-pref[a];
  }


long long a=0;
long long b=2*1e18;

while (a+1!=b)
  {
  ost=k;
  long long mini=(a+b)/2;
//  cout<<"Can we do "<<mini<<'?'<<endl;
  for (i=0; i<2*r+1; i++)
    st.push_back(0);
  sum=0;

  for (i=0; i<n; i++)
    {
    work(i, mini);
    if (ost<0)
      i=n;
    }
//  cout<<ost<<endl;
  if (ost>=0)
    a=mini;
  else
    b=mini;
  st.clear();
  }

cout<<a<<endl;



    return 0;
}