#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 300000;
int v[1 + nmax];
struct Query{
  int x;
  int y;
  int id;
  int k;
};
vector<int> frec[1 + nmax];

int lowerthan(int id, int target){
  int x = 0;
  for(int jump = (1 << 20); 0 < jump; jump /= 2)
    if(x + jump < frec[id].size() && frec[id][x + jump] <= target)
      x += jump;
  return x;
}
vector<int> cand[1 + nmax];
vector<int> dp[1 + nmax];

int freq[1 + nmax];

vector<int> extract(int x, int y){
  vector<int> temp;
  for(int i = 0; i < dp[x].size(); i++)
    temp.push_back(dp[x][i]);
  for(int i = 0; i < dp[y].size(); i++)
    temp.push_back(dp[y][i]);
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  return temp;
}

void divide(int from, int to, vector<Query> queries){
  if(from == to){
    for(int h = 0; h < queries.size(); h++)
      cand[queries[h].id].push_back(v[queries[h].x]);
  } else if(from < to){
    int mid = (from + to) / 2;
    vector<Query> queriesleft, queriesright, queriesnow;
    for(int i = 0; i < queries.size(); i++)
      if(queries[i].x <= mid && queries[i].y <= mid)
        queriesleft.push_back(queries[i]);
      else if(mid + 1 <= queries[i].x && mid + 1 <= queries[i].y)
        queriesright.push_back(queries[i]);
      else if(queries[i].x <= mid && mid + 1 <= queries[i].y)
        queriesnow.push_back(queries[i]);

    divide(from, mid, queriesleft);
    divide(mid + 1 , to, queriesright);
    set<pair<int,int>> myset;
    for(int i = from; i <= to; i++)
      dp[i].clear();

    for(int i = mid; from <= i; i--){
      if(0 < freq[v[i]])
        myset.erase({freq[v[i]], v[i]});
      freq[v[i]]++;
      myset.insert({freq[v[i]], v[i]});
      set<pair<int,int>>::iterator it;
      it = myset.end();
      it--;
      for(int h = 0; h < 5; h++){
        dp[i].push_back(it->second);
        if(it == myset.begin())
          break;
        else
          it--;
      }
    }
    for(int i = mid; from <= i; i--)
      freq[v[i]] = 0;
    myset.clear();
    for(int i = mid + 1; i <= to; i++){
      if(0 < freq[v[i]])
        myset.erase({freq[v[i]], v[i]});
      freq[v[i]]++;
      myset.insert({freq[v[i]], v[i]});
      set<pair<int,int>>::iterator it;
      it = myset.end();
      it--;
      for(int h = 0; h < 5; h++){
        dp[i].push_back(it->second);
        if(it == myset.begin())
          break;
        else
          it--;
      }
    }
    for(int i = mid + 1; i <= to; i++)
      freq[v[i]] = 0;
    for(int i = 0; i < queriesnow.size(); i++){
      int x = queriesnow[i].x;
      int y = queriesnow[i].y;
      int id = queriesnow[i].id;
      cand[id] = extract(x, y);
    }
  }
}
Query queries[1 + nmax];

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //*/

  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= n; i++)
    frec[i].push_back(0);

  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    frec[v[i]].push_back(i);
  }
  for(int i = 1;i <= q; i++) {
    cin >> queries[i].x >> queries[i].y >> queries[i].k;
    queries[i].id = i;
  }

  vector<Query> queries2;
  for(int i = 1; i <= q; i++)
    queries2.push_back(queries[i]);
  divide(1, n, queries2);
  for(int i = 1;i <= q; i++){
    int result = -1;
    int x = queries[i].x, y = queries[i].y, k = queries[i].k;
    for(int h = 0; h < cand[i].size(); h++){
      int val = cand[i][h];
      if((y - x + 1.0) / k < lowerthan(val, y) - lowerthan(val, x - 1)) {
        result = val;
        break;
      }
    }

    cout << result << '\n';
  }
  return 0;
}