#include <iostream>
#include <queue>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int l[1 + nmax], r[1 + nmax];
int sol[1 + nmax];

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> l[i] >> r[i];
  for(int i = 1;i <= n; i++)
    sol[i] = 0;
  queue<int> q;
  for(int i = 1;i <= nmax; i++) {
    for(int j = 1;j <= n; j++)
      if(l[j] == i)
        q.push(j);
    while(0 < q.size() && r[q.front()] < i)
      q.pop();
    if(0 < q.size()){
      sol[q.front()] = i;
      q.pop();
    }
  }
  for(int i = 1;i <= n; i++)
    cout << sol[i] << " ";
  cout << '\n';
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}