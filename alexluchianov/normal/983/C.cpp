#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 2000;
int a[5 + nmax], b[5 + nmax];

struct State{
  int id;
  int level;
  int v[4];

  int _count(){
    int result = 0;
    for(int i = 0; i < 4; i++)
      result += (0 < v[i]);
    return result;
  }
  bool _insert(int val){
    for(int i = 3;0 <= i; i--){
      if(v[i] <= val){
        for(int j = 1; j <= i; j++)
          v[j - 1] = v[j];
        v[i] = val;
        return 1;
      }
    }
    return 0;
  }
  bool _eject(int val){
    for(int i = 0; i < 4; i++)
      if(val == v[i]) {
        for(int j = i; 0 < j; j--)
          v[j] = v[j - 1];
        v[0] = 0;
        return 1;
      }
    return 0;
  }

  bool operator < (State const &a) const {
    if(id != a.id)
      return id < a.id;
    else if(level != a.level)
      return level < a.level;
    else
      for(int i = 0; i < 4; i++)
        if(v[i] != a.v[i])
          return v[i] < a.v[i];
    return 0;
  }
  void print(){
    cout << "Id: " << id << '\n';
    cout << "Level: " << level << '\n';
    for(int i = 0; i < 4; i++)
      cout << v[i] << " ";
    cout << '\n';
    cout << '\n';
  }
};

map<State, int> dp;

State expand(State newnode, int n){
  while(newnode._eject(newnode.level));
    for(int j = newnode._count(); j < 4; j++)
      if(newnode.id < n && a[newnode.id + 1] == newnode.level){
        newnode.id++;
        newnode._insert(b[newnode.id]);
      }
  return newnode;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> a[i] >> b[i];
  queue<State> q;
  State start = {0, 1, 0, 0, 0, 0};
  q.push(expand(start, n));
  dp[expand(start, n)] = 2 * n;

  while(0 < q.size()){
    State node = q.front();

    if(node.id == n && node._count() == 0){
      cout << dp[node];
      return 0;
    }
    q.pop();
    if(1 < node.level){
      State newnode = node;
      newnode.level--;
      newnode = expand(newnode, n);
      if(dp[newnode] == 0){
        q.push(newnode);
        dp[newnode] = dp[node] + 1;
      }
    }
    if(node.level < 9){
      State newnode = node;
      newnode.level++;
      newnode = expand(newnode, n);
      if(dp[newnode] == 0){
        q.push(newnode);
        dp[newnode] = dp[node] + 1;
      }
    }
  }
  cout << -1;
  return 0;
}