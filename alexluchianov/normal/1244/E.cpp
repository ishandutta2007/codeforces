#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int const nmax = 100000;
int v[1 + nmax];
ll v2[1 + nmax];
ll scount[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  sort(v + 1, v + n + 1);

  int vp = 0;
  for(int i = 1;i <= n; i++) {
    if(v[i] != v[i - 1])
      v2[++vp] = v[i];
    scount[vp]++;
  }

  int from = 1, to = vp;

  while(0 < k && from < to){
    if(scount[from] < scount[to]){
      if((v2[from + 1] - v2[from]) * scount[from] <= k){
        k -= (v2[from + 1] - v2[from]) * scount[from] ;
        scount[from + 1] += scount[from];
        from++;
      } else {
        int mv = k / scount[from];
        cout << v2[to] - v2[from] - mv;
        return 0;
      }
    } else {
      if((v2[to] - v2[to - 1]) * scount[to] <= k){
        k -= (v2[to] - v2[to - 1]) * scount[to];
        scount[to - 1] += scount[to];
        to--;
      } else {
        int mv = k / scount[to];
        cout << v2[to] - v2[from] - mv;
        return 0;
      }
    }
  }
  cout << 0;
  return 0;
}