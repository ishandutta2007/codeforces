#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 25
#define maxm 25

using namespace std;
typedef long long ll;

int n,m,q;
string s[maxn],t[maxm];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i = 1;i <= n;i++) cin >> s[i % n];
  for(int i = 1;i <= m;i++) cin >> t[i % m];
  cin >> q;
  for(int i = 1;i <= q;i++){
    int y;
    cin >> y;
    cout << s[y % n] + t[y % m] << '\n';
  }
  return 0;
}