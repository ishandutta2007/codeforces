#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 4008;

struct triple
{
  int first, second, third;
};

bool vis[1000][N][2];
int d[1000][N][2];
triple par[1000][N][2];
int dg[1000][N][2];

string solve(int a)
{
  int kek = 2002;
  for (int i = 0; i < a; i++)
  {
    for (int j = 0; j < N; j++) vis[i][j][0] = vis[i][j][1] = 0;
  }
  queue <triple> q;
  for (int dig = 0; dig < 10; dig++)
  {
    int ndig = (dig * a) % 10;
    int nj = (dig * a) / 10;
    bool flag = (dig != 0);
    vis[nj][kek + ndig * a - dig][flag] = true;
    d[nj][kek + ndig * a - dig][flag] = 0;
    par[nj][kek + ndig * a - dig][flag] = {-1, -1};
    dg[nj][kek + ndig * a - dig][flag] = dig;
    q.push({nj, kek + ndig * a - dig, flag});
  }
  while (!q.empty())
  {
    int i = q.front().first, j = q.front().second, flag = q.front().third;
    if (i == 0 && j == kek && flag)
    {
      int x = i, y = j, z = flag;
      string str = "";
      while (x != -1)
      {
        if (!str.empty() || dg[x][y][z] != 0)
          str += (dg[x][y][z] + '0');
        auto go = par[x][y][z];
        x = go.first, y = go.second,z = go.third;
      }
      return str;
      //break;
    }
    q.pop();
    for (int dig = 0; dig < 10; dig++)
    {
      int ndig = (i + a * dig) % 10;
      int ni = (i + a * dig) / 10;
      int nval = j + ndig * a - dig;
      int nflag = (flag || (dig != 0));
      if (nval >= 0 && nval < N && !vis[ni][nval][nflag])
      {
        d[ni][nval][nflag] = d[i][j][flag] + 1;
        vis[ni][nval][nflag] = true;
        par[ni][nval][nflag] = {i, j, flag};
        dg[ni][nval][nflag] = dig;
        q.push({ni, nval, nflag});
      }
    }
  }
  return "-1";
}

int main()
{
#ifndef ONLINE_JUDGE
 // freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a;
  cin >> a;
  cout << solve(a) << endl;
  /*
  //freopen("pupa", "w", stdout);
  for (int a = 2; a <= 1000; a++)
  {
    if (solve(a) == "-1") cout << a << endl;
  }
   */
}