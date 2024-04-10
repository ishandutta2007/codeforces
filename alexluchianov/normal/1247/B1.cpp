#include <iostream>

using namespace std;

int const nmax = 1000000;
int v[1 + nmax];
int frec[1 + nmax];
int sol = 0;

void addsol(int x){
  frec[x]++;
  if(frec[x] == 1)
    sol++;
}
void delsol(int x){
  frec[x]--;
  if(frec[x] == 0)
    sol--;
}

void solve(){
  int n, k, d;
  cin >> n >> k >> d;
  sol = 0;

  for(int i = 1;i <= n; i++)
    cin >> v[i];

  for(int i = 1;i <= d; i++)
    addsol(v[i]);
  int result = sol;
  for(int i = d + 1;i <= n; i++) {
    addsol(v[i]);
    delsol(v[i - d]);
    result = min(result, sol);
  }
  for(int i = n - d + 1; i <= n; i++)
    delsol(v[i]);
  cout << result << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}