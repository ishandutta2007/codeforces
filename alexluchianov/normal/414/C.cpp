#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = (1 << 20);
int const lgmax = 20;
int v[1 + nmax];
ll inv[1 + lgmax], inv2[1 + lgmax];

int aib[1 + nmax];
void normalize(int n){
  map<int,int> code;
  vector<int> temp;
  for(int i = 1;i <= (1 << n); i++)
    temp.push_back(v[i]);
  sort(temp.begin(), temp.end());
  code[temp[0]] = 1;
  for(int i = 1; i < temp.size(); i++)
    if(temp[i - 1] != temp[i])
      code[temp[i]] = code[temp[i - 1]] + 1;
  for(int i = 1;i <= (1 << n); i++)
    v[i] = code[v[i]];
}


void update(int x, int val){
  if(x == 0)
    return ;
  while(x <= nmax){
    aib[x] += val;
    x += x ^ (x & (x - 1));
  }
}
int query(int x){
  int result = 0;
  while(0 < x){
    result += aib[x];
    x = x & (x - 1);
  }
  return result;
}

void solve(int from, int to, int n){
  if(n == 0)
    return ;
  else{
    int mid = (from + to) / 2;
    for(int i = from; i <= mid; i++)
      update(v[i], 1);
    for(int i = mid + 1;i <= to; i++){
      inv[n] += (mid - from + 1) - query(v[i]);
      inv2[n] += query(v[i] - 1);
    }
    for(int i = from; i <= mid; i++)
      update(v[i], -1);
    solve(from, mid, n - 1);
    solve(mid + 1, to, n - 1);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n;
  for(int i = 1;i <= (1 << n); i++)
    cin >> v[i];
  normalize(n);
  solve(1, (1 << n), n);
  cin >> m;
  for(int i = 1;i <= m; i++){
    int a;
    cin >> a;
    for(int i = 1; i <= a; i++)
      swap(inv[i], inv2[i]);
    ll result = 0;
    for(int i = 1;i <= 20; i++)
      result += inv[i];
    cout << result << '\n';
  }
  return 0;
}