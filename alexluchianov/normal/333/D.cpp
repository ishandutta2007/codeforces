#include <iostream>
#include <bitset>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int v[1 + nmax][1 + nmax];
bitset<1 + nmax> mat[1 + nmax];

int n, m;
map<int,int> code;
map<int,int> decode;

void normalize(){
  vector<int> temp;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      temp.push_back(v[i][j]);
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++){
    code[temp[i]] = 1 + i;
    decode[1 + i] = temp[i];
  }
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      v[i][j] = code[v[i][j]];
}
int frec[1 + nmax][1 + nmax];

bool test(int x){
  for(int i = 1;i <= m; i++)
    for(int j = 1;j <= m; j++)
      frec[i][j] = 0;

  for(int i = 1;i <= n; i++){
    vector<int> pos;
    for(int j = 1; j <= m; j++)
      if(x <= v[i][j])
        pos.push_back(j);
    for(int h = 0; h < pos.size(); h++)
      for(int h2 = h + 1; h2 < pos.size(); h2++){
        int x = pos[h], y = pos[h2];
        if(frec[x][y] == 1)
          return 1;
        frec[x][y] = 1;
      }
  }
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      cin >> v[i][j];
  normalize();
  int x = 0;
  for(int jump = (1 << 20); 0 < jump; jump /= 2){
    if(test(x + jump) == 1)
      x += jump;
  }
  cout << decode[x];
  return 0;
}