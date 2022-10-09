#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll in[1 + nmax], out[1 + nmax];

vector<pair<pair<ll,ll>, ll>> op;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    ll x, y, cost;
    cin >> x >> y >> cost;
    out[x] += cost;
    in[y] += cost;
  }
  for(int i = 1;i <= n; i++){
    ll val = MIN(in[i], out[i]);
    in[i] -= val;
    out[i] -= val;
  }

  ll ptr = 1;
  for(int i = 1;i <= n; i++){
    if(0 < out[i]){
      while(ptr <= n && in[ptr] == 0)
        ptr++;
      while(0 < out[i]){
        ll val = MIN(out[i], in[ptr]);
        op.push_back({{i, ptr}, val});
        out[i] -= val;
        in[ptr] -= val;
        while(ptr <= n && in[ptr] == 0)
          ptr++;
      }
    }
  }

  cout << op.size() << '\n';
  for(int i = 0; i < op.size(); i++)
    cout << op[i].first.first << " " << op[i].first.second << " " << op[i].second << '\n';
  return 0;
}