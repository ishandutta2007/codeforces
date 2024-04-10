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

struct vertex
{
  ll a,b,c,d;
};

ll n,i,j,m;
vector <string> a[kk/2],b[kk/2],w[kk/2];
vector <vertex> ans;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    {
    string s;
    cin>>s;
    a[i].push_back(s);
    w[i].push_back("");
    }
for (i=0; i<n; i++)
  for (j=0; j<m; j++)
    {
    string s;
    cin>>s;
    b[i].push_back(s);
    }
for (i=n-1; i>=0; i--)
  {
  ll f0=0;
  ll f1=0;

  for (j=m-1; j>=0; j--)
    while (a[i][j].size())
      {
      if (a[i][j].back()-'0')
        {
        if (j!=1)
          {
          ans.push_back({i, j, i, 1});
          if (i!=0)
            f1++;
          }
        else
          {
          if (i!=0)
            {
//            w[0][1]+='1';
            ans.push_back({i, 1, 0, 1});
            }
          else
            {
//            w[0][1]+='1';
            ans.push_back({0, 1, 1, 1});
            ans.push_back({1, 1, 0, 1});
            }
          }
        }
      else
        {
        if (j!=0)
          {
//          w[i][0]+='0';
          ans.push_back({i, j, i, 0});
          if (i!=0)
            f0++;
          }
        else
          {
          if (i!=0)
            {
//            w[0][0]+='0';
            ans.push_back({i, 0, 0, 0});
            }
          else
            {
//            w[0][0]+='0';
            ans.push_back({0, 0, 1, 0});
            ans.push_back({1, 0, 0, 0});
            }

          }
        }
      a[i][j].pop_back();
      }

  while (f0)
    ans.push_back({i, 0, 0, 0}), f0--;
  while (f1)
    ans.push_back({i, 1, 0, 1}), f1--;
  }

for (i=0; i<n; i++)
  {
  for (j=2; j<m; j++)
    {
    while (b[i][j].size())
      {
      if (b[i][j].back()-'0')
        {
//        w[i][1].pop_back();
        if (i!=0)
          ans.push_back({0, 1, i, 1});
        ans.push_back({i, 1, i, j});
        }
      else
        {
//        w[i][0].pop_back();
        if (i!=0)
          ans.push_back({0, 0, i, 0});
        ans.push_back({i, 0, i, j});
        }
      b[i][j].pop_back();
      }
    }
  }

for (i=n-1; i>=2; i--)
  {
  for (auto s:b[i][1])
    if (s=='0')
      ans.push_back({0, 0, i, 0});
  for (auto s:b[i][0])
    if (s=='1')
      ans.push_back({0, 1, i, 1});
  while (b[i][1].size())
    {
    if (b[i][1].back()=='1')
      ans.push_back({0, 1, i, 1});
    else
      ans.push_back({i, 0, i, 1});
    b[i][1].pop_back();
    }
  while (b[i][0].size())
    {
    if (b[i][0].back()=='0')
      ans.push_back({0, 0, i, 0});
    else
      ans.push_back({i, 1, i, 0});
    b[i][0].pop_back();
    }
  }

for (i=1; i<2; i++)
  {
  for (auto s:b[i][1])
    if (s=='0')
      ans.push_back({0, 0, i, 0});
  for (auto s:b[0][0])
    if (s=='0')
      ans.push_back({0, 0, i, 0});

  for (auto s:b[i][0])
    if (s=='1')
      ans.push_back({0, 1, i, 1});
  for (auto s:b[0][1])
    if (s=='1')
      ans.push_back({0, 1, i, 1});
  }

for (i=0; i<2; i++)
  {
  while (b[i][0].size())
    {
    if (b[i][0].back()=='1')
      ans.push_back({i, 1, i, 0});
    else
      ans.push_back({1-i, 0, i, 0});
    b[i][0].pop_back();
    }
  while (b[i][1].size())
    {
    if (b[i][1].back()=='0')
      ans.push_back({i, 0, i, 1});
    else
      ans.push_back({1-i, 1, i, 1});
    b[i][1].pop_back();
    }
  }


cout<<ans.size()<<endl;
for (auto i:ans)
  {
  cout<<i.a+1<<' ';
  cout<<i.b+1<<' ';
  cout<<i.c+1<<' ';
  cout<<i.d+1<<' ';
  cout<<'\n';
  }




    return 0;
}