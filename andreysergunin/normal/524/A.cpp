#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

const int N = 200;

bool graph[N][N];
std::map<int,int> ids;
std::map<int,int> rids;
std::vector<int> f[N];

int main() {
  int m,k;
  int mid = 0;
  scanf("%d%d",&m,&k);
  for (int i=0; i<m; i++) {
    int a,b;
    scanf("%d%d",&a,&b);
    if (ids.find(a)==ids.end()) {
      ids[a] = mid; rids[mid] = a; a = mid++;
    } else a = ids[a];
    if (ids.find(b)==ids.end()) {
      ids[b] = mid; rids[mid] = b; b = mid++;
    } else b = ids[b];
    graph[a][b] = graph[b][a] = true;
  }
  for (int i=0; i<mid; i++) {
    for (int j=0; j<mid; j++) {
      if (i==j || graph[i][j]) continue;
      int nf = 0, ncf = 0;
      for (int l=0; l<mid; l++) {
        if (graph[i][l]) nf++;
        if (graph[i][l] && graph[j][l]) ncf++;
      }
      if (ncf*1.0d/nf >= k/100.0d) f[i].push_back(rids[j]);
    }
    std::sort(f[i].begin(),f[i].end());
  }
  for (std::map<int,int>::iterator i = ids.begin(); i!=ids.end(); i++) {
    printf("%d: %d",(*i).first,f[(*i).second].size());
    for (int j=0; j<f[(*i).second].size(); j++) printf(" %d",f[(*i).second][j]);
    putchar('\n');
  }
  return 0;
}