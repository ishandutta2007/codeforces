#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long mod=kk*kk*kk+7;
const long long con=1073676287;
const long long con2=9369319;
long long i,n,j,ans,len;
vector <string> s;
vector <long long> m,siz,sum,sh;
bool viv=false;

vector <long long> arr[kk],raz[kk];



solve(long long i, long long j)
{
if (viv)
  cout<<"From "<<i<<" to "<<j<<endl;
long long l=n-i;
long long code=arr[i][j];
long long econom=0;
long long write=0;
long long kol=0;
for (long long u=j; u<l; u++)
  {
  if (arr[i][u]==code)
    {
    kol++;
    if (viv)
      cout<<u<<' ';
    econom+=raz[i][u];
    write+=(i+1);
    u+=i;
    }
  }
if (viv)
  {
  cout<<endl;
  cout<<"Change: ";
  cout<<write<<' '<<econom*(-1ll)<<endl;
  }

if (kol>1)
  {
  ans=min(ans, len-econom+write);
  if (viv)
    cout<<"OK "<<ans<<endl;
  }
}


int main()
{
//viv=true;
srand(time(0));
cin>>n;
for (i=0; i<n; i++)
  {
  string ss;
  cin>>ss;
  s.push_back(ss);
  siz.push_back(ss.size());
  }
sum.push_back(0);
for (i=0; i<n; i++)
  sum.push_back(sum.back()+siz[i]);
ans=sum.back()+n-1;
len=ans;


for (i=0; i<26; i++)
  {
  long long a=rand()%10000;
  long long b=rand()%10000;
  a*=10000;
  a+=b;
  sh.push_back(a);
  }
if (viv)
{
  cout<<"Length is "<<ans<<endl;
  cout<<"Randomize:"<<endl;
  for (i=0; i<26; i++)
    cout<<sh[i]<<' ';
  cout<<endl;
}
for (i=0; i<n; i++)
  {
  long long l=s[i].size();
  long long nc=0;
  for (j=0; j<l; j++)
    {
    long long z=sh[s[i][j]-'a'];
    nc*=con;
    nc%=mod;
    nc+=z;
    nc%=mod;
    }
  m.push_back(nc);
  }
if (viv)
{
  cout<<"Words"<<endl;
  for (i=0; i<n; i++)
    cout<<m[i]<<' ';
  cout<<endl;
}

for (i=0; i<n; i++)
  {
  long long nc=0;
  for (j=i; j<n; j++)
    {
    long long z=m[j];
    nc*=con2;
    nc%=mod;
    nc+=z;
    nc%=mod;
    arr[j-i].push_back(nc);
    raz[j-i].push_back(sum[j+1]-sum[i]+j-i);
    if (viv)
      cout<<"From "<<i<<" to "<<j<<" size="<<raz[j-i].back()<<" code="<<arr[j-i].back()<<endl;
    }
  }


for (i=0; i<n; i++)
  {
  long long l=n-i;
  for (j=0; j<l; j++)
    solve(i, j);
  }


cout<<ans;


    return 0;
}