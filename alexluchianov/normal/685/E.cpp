#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1000;
int const edgemax = 200000;
int v[1 + edgemax][2];
bitset<1 + nmax> dp[1 + edgemax];
bitset<1 + nmax> dp2[1 + edgemax];

struct Query{
  int x;
  int y;
  int start;
  int stop;
  int id;
};
bitset<1 + nmax> sol[1 + edgemax][2];
int finalsol[1 + edgemax];

void over(int pos){
  dp[pos].reset();
  dp[pos][pos] = 1;
  dp2[pos].reset();
  dp2[pos][pos] = 1;
}

vector<pair<int,int>> queries[1 + edgemax];

void divide(int from, int to, vector<Query> query){
  if(from == to){
    for(int i = 0; i < query.size(); i++){
      int x = query[i].start;
      int y = query[i].stop;
      int id = query[i].id;
      if(x == y)
        finalsol[id] = 1;
      else if((x == v[from][0] && y == v[from][1]) || (x == v[from][1] && y == v[from][0]))
        finalsol[id] = 1;
    }
    return ;
  }

  int mid = (from + to) / 2;
  vector<Query> queryleft, queryright, querynow;

  for(int i = 0; i < query.size(); i++){
    if(query[i].y <= mid)
      queryleft.push_back(query[i]);
    else if(mid + 1 <= query[i].x)
      queryright.push_back(query[i]);
    else
      querynow.push_back(query[i]);
  }

  divide(from, mid, queryleft);
  divide(mid + 1, to, queryright);

  for(int i = 0; i < querynow.size(); i++) {
    queries[querynow[i].x].push_back({querynow[i].start, querynow[i].id});
    queries[querynow[i].y].push_back({querynow[i].stop, querynow[i].id});
  }

  for(int i = mid; from <= i; i--){
    dp[v[i][0]] |= dp[v[i][1]];
    dp[v[i][1]] |= dp[v[i][0]];
    for(int h = 0; h < queries[i].size(); h++){
      int id = queries[i][h].second;
      sol[id][0] = dp[queries[i][h].first];
    }
  }

  for(int i = mid + 1;i <= to; i++) {
    dp2[v[i][0]] |= dp2[v[i][1]];
    dp2[v[i][1]] |= dp2[v[i][0]];
    for(int h = 0; h < queries[i].size(); h++){
      int id = queries[i][h].second;
      sol[id][1] = dp2[queries[i][h].first];
    }
  }

  for(int i = 0; i < querynow.size(); i++){
    int id = querynow[i].id;
    finalsol[id] = (0 < (sol[id][0] & sol[id][1]).count());
  }

  for(int i = from; i <= to; i++)
    queries[i].clear();

  for(int i = from; i <= to; i++) {
    over(v[i][0]);
    over(v[i][1]);
  }

}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 1;i <= m; i++)
    cin >> v[i][0] >> v[i][1];
  vector<Query> query;
  for(int i = 1;i <= q; i++){
    int x, y, start, stop;
    cin >> x >> y >> start >> stop;
    query.push_back({x, y, start, stop, i});
  }

  for(int i = 1;i <= n; i++)
    over(i);

  divide(1, m, query);
  for(int i = 1; i <= q; i++)
    if(finalsol[i] == 0)
      cout << "No\n";
    else
      cout << "Yes\n";

  return 0;
}
/*
5 4 1
1 2
2 3
3 4
3 5
1 2 1 3
*/