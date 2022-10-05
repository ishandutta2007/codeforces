#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
long long n,i,j;
vector <long long> m;
//map <long long, long long> mp,locmp;
long long mp[2*ml],locmp[2*ml];
long long maxi;
bool deb=false;
bool sam=false;
long long dey;
ifstream in;

void addlin(long long x)
{
long long i;
for (i=0; i<x; i++)
  {
  locmp[i+1]++;
  dey++;
  }
}

void addpr(long long x, long long y)
{
long long z=1;
long long x1=0;
long long y1=0;
long long kol=0;
long long n=x+y;
//n+=2;
if (deb)
  cout<<"-----Size "<<x<<" on "<<y<<endl;
while (z<n)
  {
  dey++;
  z++;
  kol++;
  if (x1==x)
    {
    x1--;
    kol--;
    }
  if (y1==y)
    {
    y1--;
    kol--;
    }
  x1++;
  y1++;
  locmp[z]+=kol;
  if (deb)
    cout<<"------ For "<<z<<" I add "<<kol<<endl;
  }
}


void otv(long long n, long long m, long long x, long long y )
{
if (deb)
  cout<<"OK"<<endl;
cout<<n<<' '<<m<<endl;
cout<<x+1<<' '<<y+1<<endl;
long long i,j;
if (deb)
  {
  for (i=0; i<n; i++)
    {
    for (j=0; j<m; j++)
      cout<<abs(i-x)+abs(j-y)<<' ';;
    cout<<endl;
    }
  }
if (!sam)
  exit(0);
}


void solve(long long x, long long y)
{
long long i,j;
long long len=x+y-1;
for (i=0; i<=maxi; i++)
  {
  j=maxi-i;
  if (i>x)
    i=maxi;
  if (i<x&&j<y)
    {
    for (long long u=0; u<len; u++)
      locmp[u]=0;
    locmp[0]=1;
    addlin(i);
    addlin(x-i-1);
    addlin(j);
    addlin(y-j-1);
    addpr(i, j);
    addpr(i, y-j-1);
    addpr(x-i-1, j);
    addpr(x-i-1, y-j-1);
    bool viv=true;
    if (deb)
      cout<<"--Point "<<i<<' '<<j<<endl;
    for (long long u=0; u<len; u++)
      {
      if (deb)
        cout<<"----"<<u<<" have "<<locmp[u]<<" times"<<endl;
      if (locmp[u]!=mp[u])
        viv=false;
      }
    if (viv)
      otv(x, y, i, j);
    }

  }





}
int main()
{
//sam=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
if (sam)
  in.open("example_1000000.txt");
if (sam)
  in>>n;
else
  cin>>n;
for (i=0; i<n; i++)
  {
  mp[i]=0;
  locmp[i]=0;
  }
maxi=-1;
for (i=0; i<n; i++)
  {
  long long a;
  if (sam)
    in>>a;
  else
    cin>>a;
  mp[a]++;
  maxi=max(maxi, a);
  m.push_back(a);
  }

for (i=1; i<sqrt(n)+3; i++)
  if (n%i==0)
    {
    long long j=n/i;
    if (i<=j)
      {
      if (deb)
        cout<<"Try solve "<<i<<' '<<j<<endl;
      solve(i, j);
      }
    }

cout<<-1<<endl;
if (sam)
  cout<<dey;
    return 0;
}