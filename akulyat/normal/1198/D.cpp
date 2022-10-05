#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
const ll N=56;

ll n,i,j;
vector <ll> m;
vector <vector <bool>> p;
short ans[N][N][N][N];
vector <vector <short>> psum;
bool viv=false;

void prepare()
{
psum.resize(n+1);
for (auto &v:psum)
  v.resize(n+1, 0);
for (short i=0; i<n; i++)
  for (short j=0; j<n; j++)
    psum[i+1][j+1]=psum[i][j+1]+psum[i+1][j]+(short)p[i][j]-psum[i][j];
}

short sum(short x1, short y1, short x2, short y2)
{
short lans=psum[x2+1][y2+1];
lans-=psum[x1][y2+1];
lans-=psum[x2+1][y1];
lans+=psum[x1][y1];
return lans;
}

short answer(short x1, short y1, short x2, short y2)
{
if (x2<0||y2<0)
  return 0;
if (ans[x1][y1][x2][y2]!=69)
  return ans[x1][y1][x2][y2];
short lans=max(x2-x1+1, y2-y1+1);
for (short i=x1; i<=x2; i++)
  if (sum(i, y1, i, y2)==0)
    lans=min((int)lans, answer(x1, y1, i-1, y2)+answer(i+1, y1, x2, y2));
for (short i=y1; i<=y2; i++)
  if (sum(x1, i, x2, i)==0)
    lans=min((int)lans, answer(x1, y1, x2, i-1)+answer(x1, i+1, x2, y2));

ans[x1][y1][x2][y2]=lans;
return lans;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (ll i=0; i<n; i++)
  {
  vector <bool> v;
  string s;
  cin>>s;
  for (auto i:s)
    v.push_back(i=='#');
  p.push_back(v);
  }
prepare();
for (short i=0; i<n+4; i++)
  for (short j=0; j<n+4; j++)
    for (short u=0; u<n+4; u++)
      for (short y=0; y<n+4; y++)
        {
        if (i>u||j>y)
          ans[i][j][u][y]=0;
        ans[i][j][u][y]=69;
        }
cout<<ll(answer(0, 0, n-1, n-1));


    return 0;
}