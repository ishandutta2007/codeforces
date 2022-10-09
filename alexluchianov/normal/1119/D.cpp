#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll v[5 + nmax];
ll v2[5 + nmax];

struct Query{
  ll val;
  int ind;
  bool operator < (Query const a) const{
    return val < a.val;
  }
};

ll sol[5 + nmax];

Query queries[5 + nmax];

int main()
{
  int n, q;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  sort(v + 1, v + n + 1);
  for(int i = 1; i < n; i++)
    v2[i] = v[i + 1] - v[i];
  sort(v2 + 1, v2 + n);

  cin >> q;
  for(int i = 1;i <= q;i++) {
    ll l, r;
    cin >> l >> r;
    queries[i] = {r - l + 1, i};
  }
  sort(queries + 1, queries + q + 1);

  int pos = 1;
  ll result = 0;
  for(int i = 1;i <= q;i++){

    while(pos < n && v2[pos] <= queries[i].val) {
      result += v2[pos];
      pos++;
    }

    sol[queries[i].ind] = result + (n - pos + 1) * (queries[i].val) ;
  }

  for(int i = 1; i <= q; i++)
    cout << sol[i] << " ";

  return 0;
}