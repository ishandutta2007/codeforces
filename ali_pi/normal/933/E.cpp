#include<bits/stdc++.h>

#define int long long

#define err(A) cout << #A << " = " << (A) << endl

using namespace std;

const int inf = 1e17+30;
const int maxn = 300300;

int n;
int a[maxn];
int dp[maxn];
int p[maxn];

bool mark[maxn];
vector<int> ans;

void chk(int i, int x, int pr){
  if (x < dp[i])
    dp[i] = x, p[i] = pr;
}

void follow(int i){
  if (i < 1)
    return;
  mark[i] = true;
  for (int j = p[i] + 2; j < i; j ++)
    mark[j] = true;
  follow(p[i]);
}

void add(int i){
  int c = min(a[i], a[i + 1]);
  if (c){
      a[i] -= c;
      a[i + 1] -= c;
      ans.push_back(i);
    } 
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i ++)
    cin >> a[i];
  for (int i = 1; i <= n; i ++){
      dp[i] = inf;
      chk(i, dp[i - 1] + a[i], i - 1);
      chk(i, (i > 1 ? dp[i - 2] : 0) + a[i], i - 2);
      chk(i, (i > 2 ? dp[i - 3] : 0) + max(a[i], a[i - 1]), i - 3);
    }
  if (dp[n] < dp[n - 1])
    follow(n);
  else
    follow(n - 1);
  for (int i = 1; i <= n; i ++)
    if(mark[i] and a[i])
      add(i);
  for (int i = 1; i <= n; i ++)
    if(a[i] and a[i + 1])
      add(i);
  cout << ans.size() << "\n";
  for(int i:ans)
    cout << i << "\n"; 
}