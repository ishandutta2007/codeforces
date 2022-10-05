#include <bits/stdc++.h>

using namespace std;

long long n,k,s,t,i,j;
vector <pair <long long, long long> > m;
vector <long long> z,r,udv,per;
long long need;
bool viv=false;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

viv=false;


cin>>n>>k>>s>>t;
need=(2*s-t);
need=max((long long)0, need);

for (i=0; i<n; i++)
  {
  long long a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }

z.push_back(0);
for (i=0; i<k; i++)
  {long long a; cin>>a; z.push_back(a);}
z.push_back(s);
sort(z.begin(), z.end());

for (i=0; i<k+1; i++)
  r.push_back(z[i+1]-z[i]);

sort(m.begin(), m.end());
sort(r.begin(), r.end());
k++;

if (viv)
{
for (i=0; i<k; i++)
  cout<<r[i]<<' ';
cout<<endl;
}



long long can=0;
for (i=0; i<k; i++)
  {
  can+=r[k-1]-r[i];
  }

for (i=0; i<k; i++)
  udv.push_back(2*r[i]);

if (viv)
{
for (i=0; i<k; i++)
  cout<<udv[i]<<' ';
cout<<endl;
}

per.push_back(0);
for (i=1; i<k; i++)
  per.push_back(per.back()+(i)*(udv[i]-udv[i-1]));

if (viv)
  {
  for (i=0; i<k; i++)
    cout<<per[i]<<' ';
  cout<<endl;
  }

for (i=0; i<n; i++)
  {
  long long p=m[i].first;
  long long v=m[i].second;
  if (r[k-1]<=v)
    {
    long long lcan=can;
    lcan+=k*(v-r[k-1]);
    long long pp=lower_bound(udv.begin(), udv.end(), v)-udv.begin();
    pp--;
    if (pp>=0)
      {
      lcan-=per[pp];
      lcan-=(v-udv[pp])*(pp+1);
      }
    if (viv)
      cout<<p<<' '<<lcan<<endl;

    if (lcan>=need)
      {
      cout<<p<<endl;
      return 0;
      }
    }
  }

cout<<-1<<endl;


    return 0;
}