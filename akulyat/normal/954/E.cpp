#include <bits/stdc++.h>

using namespace std;

const long double eps=0.000000001;
vector <long long> p,t,davl,obz;
vector <long long> rdavl,robz;
vector <long double> itog, ritog;
vector <pair<long long, long long> > k;
long long n,tk;
long i,j;


int main()
{
cin>>n>>tk;
for (i=0; i<n; i++)
  {long a; cin>>a; p.push_back(a);}
for (i=0; i<n; i++)
  {long a; cin>>a; t.push_back(a);}
for (i=0; i<n; i++)
  k.push_back({t[i], p[i]});
sort(k.begin(), k.end());

davl.push_back(0);
for (i=0; i<n; i++)
  davl.push_back(davl[i]+k[i].second);

obz.push_back(0);
for (i=0; i<n; i++)
  obz.push_back(obz[i]+k[i].first*k[i].second);

itog.push_back(0);
for (i=1; i<=n; i++)
  itog.push_back((long double)obz[i]/(long double)davl[i]);


rdavl.push_back(0);
for (i=0; i<n; i++)
  rdavl.push_back(rdavl[i]+k[n-i-1].second);

robz.push_back(0);
for (i=0; i<n; i++)
  robz.push_back(robz[i]+k[n-i-1].first*k[n-i-1].second);

ritog.push_back(0);
for (i=1; i<=n; i++)
  ritog.push_back((long double)robz[i]/(long double)rdavl[i]);

if (tk<itog[1]||tk>ritog[1])
  {
  cout<<0;
  return 0;
  }


         /*
for (j=0; j<=n; j++)
  cout<<obz[j]<<' ';
cout<<endl;
for (j=0; j<=n; j++)
  cout<<davl[j]<<' ';
cout<<endl;
for (j=0; j<=n; j++)
  cout<<itog[j]<<' ';
cout<<endl;
          */

i=0;
while (i<=n&&itog[i]<=tk)
  i++;

bool rec=false;
if (i==n+1)
  {
  rec=true;
  i=1;
  while (i<n&&ritog[i]>=tk)
    i++;
  }

           /*
cout<<rec<<endl;
//             /*
for (j=0; j<=n; j++)
  cout<<robz[j]<<' ';
cout<<endl;
for (j=0; j<=n; j++)
  cout<<rdavl[j]<<' ';
cout<<endl;
for (j=0; j<=n; j++)
  cout<<ritog[j]<<' ';
cout<<endl;
//               */
if (rec)
  {
  //cout<<i<<endl;
  long long alr=robz[i-1];
  long long water=rdavl[i-1];

  long double l=0, r=k[n-(i-1)-1].second;
  long long ct=k[n-(i-1)-1].first;
  long double res;

  while (r-l>eps)
    {
    long double m=(l+r)/2;
    res=(alr+ct*m)/(water+m);
    if (res<tk)
      r=m;
    else
      l=m;
    }
  //cout<<res<<endl;

/*
  if (abs(tk-res)>0.1)
    {
    cout<<0;
    return 0;
    }
*/
  cout.precision(10);
  cout<<fixed<<water+l;

    return 0;
  }
long long alr=obz[i-1];
long long water=davl[i-1];

long double l=0, r=k[i-1].second;
long long ct=k[i-1].first;
long double res;

while (r-l>eps)
  {
  long double m=(l+r)/2;
  res=(alr+ct*m)/(water+m);
  if (res>tk)
    r=m;
  else
    l=m;
  }

/*
if (abs(tk-res)>0.1)
  {
  cout<<0;
  return 0;
  }
*/
cout.precision(10);
cout<<fixed<<water+l;

    return 0;
}