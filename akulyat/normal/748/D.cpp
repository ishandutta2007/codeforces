#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long mod=kk*kk*kk+7;
long long i,j,n,k;
vector <pair< pair <long long, long long>, long long > > m, m1;
vector <long long> sh;
long long ans,worst;
bool viv=false;


long long has(string s)
{
long long n=s.size();
long long h=0;

for (long i=0; i<n; i++)
  {
  h*=10;
  h%=mod;
  h+=sh[s[i]-'a'];
  h%=mod;
  }

return h;
}


int main()
{
viv=false;


srand(time(0));
for (i=0; i<26; i++)
  {
  long long a=0, b=0;
  a=rand()%10000;
  b=rand()%10000;
  sh.push_back(a*10000+b);
  }


cin>>n>>k;
for (i=0; i<n; i++)
  {
  string s,s1;
  long long a;
  cin>>s>>a;
  s1=s;
  reverse(s1.begin(), s1.end());
  m.push_back ({{has(s),  a}, has(s1)});
  m1.push_back({{has(s1), a}, has(s) });
  }

sort(m.begin(), m.end());
sort(m1.begin(), m1.end());

if (viv)
  {
  for (i=0; i<n; i++)
    cout<<m[i].first.second<<' '<<m[i].first.first<<' '<<m[i].second<<endl;
  for (i=0; i<n; i++)
    cout<<m1[i].first.second<<' '<<m1[i].first.first<<' '<<m1[i].second<<endl;
  }

i=0;
j=0;


while (i<n&&j<n)
  {
  while (i<n&&j<n&&m[i].first.first<m1[j].first.first)
    i++;
  while (i<n&&j<n&&m[i].first.first>m1[j].first.first)
    j++;
  if (i<n&&j<n)
    if (m[i].first.first==m1[j].first.first)
      {
      if (m[i].first.first!=m[i].second)
        {
        long long h=m[i].first.first;
        long long i1=i;
        long long j1=j;
        vector <long long> v,v1;
        while (i1<n&&m[i1].first.first==h)
          {
          v.push_back(m[i1].first.second);
          i1++;
          }
        while (j1<n&&m1[j1].first.first==h)
          {
          v1.push_back(m1[j1].first.second);
          j1++;
          }
        sort(v.rbegin(), v.rend());
        sort(v1.rbegin(), v1.rend());
        if (viv)
          {
          cout<<"I cout:"<<endl;
          for (long long u=0; u<v.size(); u++)
            cout<<v[u]<<' ';
          cout<<endl;
          for (long long u=0; u<v1.size(); u++)
            cout<<v1[u]<<' ';
          cout<<endl;
          cout<<"It was cout succesfully"<<endl;
          }
        i=i1; j=j1;
        long long l=v.size(), l1=v1.size();
        long long i2=0;
        while (i2<l&&i2<l1&&v[i2]+v1[i2]>=0)
          {
          ans+=v[i2]+v1[i2];
          i2++;
          }
        }
      else
        {
        long long h=m[i].first.first;
        long long i1=i;
        vector <long long> v;
        while (i1<n&&m[i1].first.first==h)
          {
          v.push_back(m[i1].first.second);
          i1++;
          }
        sort(v.rbegin(), v.rend());
        i=i1;
        long long l=v.size();
        long long i2=0;
        while (i2+1<l&&v[i2]+v[i2+1]>=0)
          {
          ans+=2*(v[i2]+v[i2+1]);
          worst=max(worst, -v[i2+1]);
          i2+=2;
          }
        if (i2<l)
          worst=max(worst, v[i2]);
        }
      }
  }

if (viv)
  cout<<ans<<' '<<worst<<endl;
cout<<ans/2+worst<<endl;

    return 0;
}