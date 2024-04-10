#include <bits/stdc++.h>

using namespace std;

int N, M;
int tbl[1005][1005];
vector<int> row[1005];
vector<int> col[1005];

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for(int i = 1; i<=N; i++){
    for(int j = 1; j<=M; j++){
      cin >> tbl[i][j];
    }
  }
  for(int i = 1; i<=N; i++){
    for(int j = 1; j<=M; j++){
      row[i].push_back(tbl[i][j]);
      col[j].push_back(tbl[i][j]);
    }
  }
  for(int i = 1; i<=N; i++){
    sort(row[i].begin(), row[i].end());
    row[i].erase(unique(row[i].begin(), row[i].end()), row[i].end());
  }
  for(int j = 1; j<=M; j++){
    sort(col[j].begin(), col[j].end());
    col[j].erase(unique(col[j].begin(), col[j].end()), col[j].end());
  }
  for(int i = 1; i<=N; i++){
    for(int j = 1; j<=M; j++){
      int cnt = 0;
      int o1 = lower_bound(row[i].begin(), row[i].end(), tbl[i][j]) - row[i].begin();
      int o2 = lower_bound(col[j].begin(), col[j].end(), tbl[i][j]) - col[j].begin();
      cnt = max(o1, o2) + max(row[i].size()-o1, col[j].size()-o2);
      //cout << o1 << " " << o2 << "\n";
      //cnt++;
      cout << cnt << " ";
    }
    cout << "\n";
  }
}