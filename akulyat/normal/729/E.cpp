#include <bits/stdc++.h>

using namespace std;

long long n,s,i,j;
vector <long long> m,p;
long long add;
long kol[300000];


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>s;
s--;


for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back(a); }
if (m[s]!=0)
  add=1;

for (i=0; i<n; i++)
  if (i!=s)
    p.push_back(m[i]);
n--;

for (i=0; i<n; i++)
  kol[p[i]]++;

vector <long long> nul;
nul.push_back(0);
for (i=1; i<=n; i++)
  {
  nul.push_back(nul.back());
  if (kol[i]==0)
    nul.back()++;
  }

vector <long long> sum;
sum.push_back(0);
for (i=1; i<=n; i++)
  {
  sum.push_back(sum.back());
  sum.back()+=kol[i];
  }

/*
for (i=0; i<=n; i++)
  cout<<sum[i]<<' ';
cout<<endl;
for (i=0; i<=n; i++)
  cout<<nul[i]<<' ';
cout<<endl;
*/

long long ans=n+add;

for (i=1; i<=n; i++)
  {
  long long lans=sum[i];
  long long ost=n-sum[i];
  lans-=(max(nul[i]-ost, (long long)0));
  lans=n-lans;

//  cout<<"Ok, length "<<i<<" create "<<lans<<endl;
  ans=min(lans+add, ans);
  }

cout<<ans;



    return 0;
}