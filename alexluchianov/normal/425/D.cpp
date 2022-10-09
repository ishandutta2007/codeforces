#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
struct Point{
  int x;
  int y;
} v[1 + nmax];
vector<int> line[1 + nmax], column[1 + nmax];
unordered_set<int> exist[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i].x >> v[i].y;
    line[v[i].x].push_back(v[i].y);
    column[v[i].y].push_back(v[i].x);
    exist[v[i].x].insert(v[i].y);
  }

  int result = 0;
  for(int i = 1;i <= n; i++) {
    if(line[v[i].x].size() < column[v[i].y].size()){
      for(int j = 0; j < line[v[i].x].size(); j++){
        int y = line[v[i].x][j];
        if(v[i].y < y){
          int d = y - v[i].y;
          if(exist[v[i].x + d].find(v[i].y) != exist[v[i].x + d].end() && exist[v[i].x + d].find(y) != exist[v[i].x + d].end())
            result++;
        }
      }
    } else{
      for(int j = 0; j < column[v[i].y].size(); j++){
        int x = column[v[i].y][j];
        if(v[i].x < x){
          int d = x - v[i].x;
          if(exist[v[i].x].find(v[i].y + d) != exist[v[i].x].end() && exist[x].find(v[i].y + d) != exist[x].end())
            result++;
        }
      }
    }
  }
  cout << result;
  return 0;
}