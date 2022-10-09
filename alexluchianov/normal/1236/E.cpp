#include <iostream>
#include <map>
using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];
map<int,int> dpreal;
map<int,int> dp2real;
int decal = 0, decal2 = 0;

int dp(int pos){
  return dpreal[pos - decal];
}

void setdp(int pos, int val){
  dpreal[pos - decal] = val;
}

int dp2(int pos){
  return dp2real[pos - decal2];
}
void setdp2(int pos, int val){
  dp2real[pos - decal2] = val;
}

int main()
{
  int n, m;
  cin >> n >> m;
  if(n == 1) {
    cout << 0;
    return 0;
  }
  for(int i = 1;i <= m; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    setdp(i, 1);

  for(int i = 1;i <= m; i++){
    decal--;///all the minimums are lowered by 1
    setdp(1, dp(1) + dp(0));
    setdp(0, 0);

    setdp(v[i] + 1, dp(v[i]) + dp(v[i] + 1));
    setdp(v[i], 0);
  }

  decal--;///all the minimums are lowered by 1
  setdp(1, dp(1) + dp(0));
  setdp(0, 0);

  for(int i = 1;i <= n; i++)
    setdp2(i, 1);

  for(int i = 1;i <= m; i++){
    decal2++; ///all the maximums are increased by 1
    setdp2(n, dp2(n) + dp2(n + 1));
    setdp2(n + 1, 0);

    setdp2(v[i] - 1, dp2(v[i] - 1) + dp2(v[i]));
    setdp2(v[i], 0);
  }

  decal2++; ///all the maximums are increased by 1
  setdp2(n, dp2(n) + dp2(n + 1));
  setdp2(n + 1, 0);

  ll result = n;
  for(int i = 1;i <= n; i++)
    result += 1LL * i * dp2(i) - 1LL * i * dp(i);

  cout << result;
  return 0;
}