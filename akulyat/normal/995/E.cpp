#include <bits/stdc++.h>

using namespace std;

long long s,e,p,i;
vector <long long> m1[200000];
vector <long long> m2[200000];
vector <long long> ans;
map <long long, pair <long long, long long> > mp1;

long long obr(long long v, long long mod)
{
long long i=0;
long long st=mod-2;
vector <long long> bin;
long long l=0;
while(st>0)
  {
  bin.push_back(st&1);
  st/=2;
  l++;
  }

vector <long long> sq;
sq.push_back(v);
for (i=1; i<l; i++)
  {
  long long s=sq.back();
  s*=s;
  s%=mod;
  sq.push_back(s);
  }


long long ans=1;
for (i=0; i<l; i++)
  if (bin[i])
    {
    ans*=sq[i];
    ans%=mod;
    }

//cout<<v<<'*'<<ans<<"=="<<1<<" mod "<<mod<<endl;
return ans;
}

long long go(long long v, long long t)
{
if (t==0)
  return (v+1)%p;
if (t==1)
  return (v-1+p)%p;
if (t==2)
  return obr(v, p);
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
srand(time(0));
cin>>s>>e>>p;

/*
if ((e-s+p)%p<=200)
  {
  long long l=(e-s+p)%p;
  cout<<l<<endl;
  for (long long i=0; i<l; i++)
    cout<<"1 ";
  return 0;
  }

if ((s-e+p)%p<=200)
  {
  long long l=(s-e+p)%p;
  cout<<l<<endl;
  for (long long i=0; i<l; i++)
    cout<<"2 ";
  return 0;
  }
*/


long long kol=8000;
long long shag=99;
for (long long u=0; u<kol; u++)
  {
//  cout<<u<<endl;
  long long v=s;
  m1[u].push_back(rand()%3);
  v=go(v, m1[u][0]);
  mp1[v]={u, 0};
  for (i=1; i<shag; i++)
    {
    long long now=rand()%3;
    long long last=m1[u].back();
    while (((last^now)==1)||((last*now)==4))
      now=rand()%3;
    m1[u].push_back(now);
    v=go(v, now);
    mp1[v]={u, i};
    }
  }


for (long long u=0; u<kol; u++)
  {
  long long v=e;

  i=0;
  m2[u].push_back(rand()%3);
  v=go(v, m2[u][0]);
  if (mp1.find(v)!=mp1.end())
    {
//    cout<<"Zhivem, poluchili "<<v<<endl;
    long long j;
    for (j=0; j<=i; j++)
      {
      long long z=m2[u][j];
      if (z!=2)
        z=1-z;
      ans.push_back(z);
      }
    reverse(ans.begin(), ans.end());
    long long a=mp1[v].first;
    long long b=mp1[v].second;
/*
    cout<<a<<' '<<b<<' '<<endl;
    for (long long q=0; q<=b; q++)
      cout<<m1[a][q]<<' ';
    cout<<m2[u][0];
    cout<<"|||"<<endl;
*/
    for (j=b; j>=0; j--)
      ans.push_back(m1[a][j]);
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    long long toc=s;
    for (i=0; i<ans.size(); i++)
      {
      toc=go(toc, ans[i]);
 //     cout<<'{'<<ans[i]+1<<' '<<toc<<'}';
      cout<<ans[i]+1<<' ';
      }
//    if (p==1000000007)
//      cout<<endl<<toc;
    return 0;
    }
  for (i=1; i<shag; i++)
    {
    long long now=rand()%3;
    long long last=m1[u].back();
    while (((last^now)==1)||((last*now)==4))
      now=rand()%3;
    m2[u].push_back(now);
    v=go(v, now);
    if (mp1.find(v)!=mp1.end())
      {
//      cout<<"Zhivem, poluchili "<<v<<endl;
      long long j;
      for (j=0; j<=i; j++)
        {
        long long z=m2[u][j];
        if (z!=2)
          z=1-z;
        ans.push_back(z);
        }
//      reverse(ans.begin(), ans.end());
      long long a=mp1[v].first;
      long long b=mp1[v].second;
      for (j=b; j>=0; j--)
        ans.push_back(m1[a][j]);
      reverse(ans.begin(), ans.end());

      cout<<ans.size()<<endl;
      long long toc=s;
      for (i=0; i<ans.size(); i++)
        {
        toc=go(toc, ans[i]);
//        cout<<'{'<<ans[i]+1<<' '<<toc<<'}';
        cout<<ans[i]+1<<' ';
        }
//      if (p==1000000007)
//        cout<<endl<<toc;
      return 0;
      }

    }
  }







    return 0;
}