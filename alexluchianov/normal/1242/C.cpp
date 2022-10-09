#include <iostream>
#include <map>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 15;
int const kmax = 5000;
int const inf = 1000000001;

ll v[5 + nmax][5 + kmax], sum[5 + nmax];
map<ll,pair<int,int>> findp;
ll desiredsum = 0;

ll dat[1 + nmax],luat[1 + nmax];
int n;

void reset(){
  for(int i = 0;i < n; i++)
    dat[i] = luat[i] = inf;
}

int findcycle(int start, int pos, int print){
  int realstart = start;
  if(print == 0)
    reset();

  int mask = 0;
  while(dat[start] == inf){
    mask |= (1 << start);
    dat[start] = v[start][pos];

    luat[start] = desiredsum - sum[start] + dat[start];
    //cout << desiredsum << " " << sum[start] << " " << dat[start] << '\n';
    //cout << ":" << start << " " << pos << " " << dat[start] << " " << luat[start] << '\n';

    if(findp.find(luat[start]) == findp.end())
      return -1;
    //cout << findp[luat[start]].first << " " << findp[luat[start]].second << '\n';
    int pos2, start2;
    pos2 = findp[luat[start]].second;
    start2 = findp[luat[start]].first;
    if(dat[start2] != inf && dat[start2] != luat[start])
      return -1;
    pos = pos2;
    start = start2;
  }

  if(start == realstart)
    return mask;
  else
    return -1;
}

int dp[(1 << nmax)];
int last[(1 << nmax)];
pair<int,int> write[(1 << nmax)];
int main()
{
  cin >> n;
  for(int i = 0;i < n; i++){
    cin >> v[i][0];
    for(int j = 1;j <= v[i][0]; j++) {
      cin >> v[i][j];
      desiredsum += v[i][j];
      sum[i] += v[i][j];
      findp[v[i][j]] = {i, j};
    }
  }
  desiredsum /= n;
  //cout << desiredsum << '\n';
  //*
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= v[i][0]; j++) {
      int mask = findcycle(i, j, 0);
      if(0 <= mask && dp[mask] == 0) {
        dp[mask] = 1;
        last[mask] = 0;
        write[mask] = {i, j};
      }
    }
  }

  for(int mask = 0; mask < (1 << n); mask++){
    for(int mask2 = mask; 0 < mask2; mask2 = (mask2 - 1) & mask){
      if(0 < dp[mask])
        continue;
      else if(0 < dp[mask2] && last[mask2] == 0 && 0 < dp[mask ^ mask2]) {
        dp[mask] = 1;
        last[mask] = mask ^ mask2;
      }
    }
  }

  if(dp[(1 << n) - 1] == 0)
    cout << "No\n";
  else{
    int mask = (1 << n) - 1;
    reset();
    while(0 < mask){
      findcycle(write[mask ^ last[mask]].first, write[mask ^ last[mask]].second, 1);
      mask = last[mask];
    }
    cout << "Yes\n";
    for(int i = 0;i < n; i++) {
      cout << dat[i] << " ";
      for(int j = 0; j < n; j++)
        if(luat[j] == dat[i])
          cout << j + 1;
      cout << '\n';
    }
  }
  //*/
  return 0;
}