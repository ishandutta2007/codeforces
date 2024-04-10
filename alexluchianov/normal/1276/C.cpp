#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 400000;
int v[1 + nmax];

map<int, int> code;
map<int, int> decode;

int normalize(int n){
  vector<int> temp;
  for(int i = 1;i <= n; i++)
    temp.push_back(v[i]);
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++){
    code[temp[i]] = 1 + i;
    decode[1 + i] = temp[i];
  }
  for(int i = 1;i <= n; i++)
    v[i] = code[v[i]];
  return code.size();
}

int coef[1 + nmax];
vector<vector<int>> sol, seen;

void nxt(int &x, int &y, int bestn, int bestm){
  x++;
  y++;
  if(x == bestn){
    x = 0;
    y = y - bestn + 1;
  }
  x = x % bestn;
  if(y < 0)
    y = (y + bestm) % bestm;
  y = y % bestm;
}

void solve(int n, int bestn, int bestm, int lim){
  sol.resize(bestn);
  seen.resize(bestn);
  for(int i = 0; i < bestn; i++)
    sol[i].resize(bestm);
  for(int i = 0; i < seen.size(); i++)
    seen[i].resize(bestm);

  for(int i = 1;i <= lim; i++)
    coef[i] = 0;
  for(int i = 1;i <= n; i++)
    if(coef[v[i]] < bestn)
      coef[v[i]]++;

  int x = 0, y = 0;

  for(int i = 1;i <= lim; i++)
    if(coef[i] == bestn){
      while(0 < coef[i] && 0 == seen[x][y]){
        seen[x][y] = 1;
        sol[x][y] = i;
        coef[i]--;
        nxt(x, y, bestn, bestm);
      }
    }


  int ptr = 1;
  while(seen[x][y] == 0){
    seen[x][y] = 1;
    while(ptr < lim && coef[ptr] == 0 )
      ptr++;
    sol[x][y] = ptr;
    coef[ptr]--;

    nxt(x, y, bestn, bestm);
  }
}

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 // */

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  int lim = normalize(n);
  for(int i = 1;i <= n; i++)
    coef[v[i]]++;
  sort(coef + 1, coef + lim + 1);

  int ptr = 0, sum = 0;
  int result = 0, bestn = 0, bestm = 0;

  for(int i = 1;i <= n; i++){
    while(ptr < lim && coef[ptr + 1] <= i){
      sum += coef[ptr + 1];
      ptr++;
    }
    int total = sum + (lim - ptr) * i;
    int target = total / i;

    if(target < i)
      continue;

    if(result < i * target){
      result = i * target;
      bestn = i;
      bestm = target;
    }
  }

  cout << result << '\n';
  cout << bestn << " " << bestm << '\n';
  solve(n, bestn, bestm, lim);

  for(int i = 0; i < bestn; i++) {
    for(int j = 0; j < bestm; j++)
      cout << decode[sol[i][j]] << " ";
    cout << '\n';
  }

  return 0;
}