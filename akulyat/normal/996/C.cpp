#include <bits/stdc++.h>

using namespace std;

long long n,k,i,j,kol,st;
long long f[1000],s[1000];
vector <long long> p[5];
string ans;
vector <long long> m;


string sss(long long v)
{
if (v==0)
  return "0";

string s1;
while  (v>0)
  {
  s1+=char((v%10)+'0');
  v/=10;
  }
reverse(s1.begin(), s1.end());
return s1;
}

void stav()
{
for (i=1; i<=k; i++)
  if (s[i]!=-1)
    if (s[i]==f[i])
      {
      long long p=s[i];
      kol++;
      s[i]=-1;
      ans+=sss(i);
      ans+=' ';
      ans+=sss((p/n)*3+1);
      ans+=' ';
      ans+=sss(p%n+1);
      ans+=' ';
      ans+='\n';
      }
}

void check()
{
long long i;

vector <long long> nal;
for (i=0; i<2*n; i++)
  nal.push_back(0);
for (i=1; i<=k; i++)
  if (s[i]!=-1)
    nal[s[i]]=i;
long long st=0;
for (i=0; i<2*n; i++)
  if (nal[i]==0)
    st=i;

long long j=st;
while (j!=-1)
  {
//  cout<<"OK "<<j<<' ';
  long long r=j/n+2;
  long long p=j%n+1;
  long long u=j;
  if (j<n-1)
    u++;
  if (j>n)
    u--;
  if (j==n-1)
    u+=n;
  if (j==n)
    u-=n;
  long long v=nal[u];
//  cout<<u<<' '<<v<<endl;
  if (nal[j]==0&&v!=0&&u!=st)
    {
    nal[j]=nal[u];
    nal[u]=0;
    s[v]=j;
    kol++;
    ans+=sss(v);
    ans+=' ';
    ans+=sss(r);
    ans+=' ';
    ans+=sss(p);
    ans+=' ';
    ans+='\n';
    }
  j=u;

  if (j==st)
    j=-1;
  }


}

int main()
{
cin>>n>>k;
for (j=0; j<4; j++)
  {
  for (i=0; i<n; i++)
    {
    long long a;
    cin>>a;
    p[j].push_back(a);
    if (j==0||j==3)
      f[a]=(i+n*(j/3));
    else
      s[a]=(i+n*(j-1));
    }
  }

stav();
long long ost=0;
for (i=0; i<k; i++)
  if (s[i]!=-1)
    ost++;

if (ost==2*n)
  {
  cout<<-1;
  return 0;
  }

for (long long i=0; i<2*n; i++)
  {
  check();
  stav();
//  cout<<"After "<<i<<" 5 on "<<s[5]<<endl;
  }

cout<<kol<<endl;
cout<<ans;

    return 0;
}