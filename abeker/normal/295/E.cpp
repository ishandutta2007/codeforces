#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int offset = 1 << 19;

struct node {
   int cnt;
   ll sum, dist;
   node(int cnt, ll sum, ll dist) : cnt(cnt), sum(sum), dist(dist) {}
   node() : cnt(0), sum(0), dist(0) {}
};

int N, M;
int x[MAXN], y[MAXN];
int type[MAXN], a[MAXN], b[MAXN];
vector <int> V;
node t[2 * offset];

void load() {
   scanf("%d", &N);
   for (int i = 0; i < N; i++)
       scanf("%d", x + i);
   scanf("%d", &M);
   for (int i = 0; i < M; i++)
       scanf("%d%d%d", type + i, a + i, b + i);
}

node merge(node L, node R) {
   node res;
   res.cnt = L.cnt + R.cnt;
   res.sum = L.sum + R.sum;
   res.dist = L.dist + R.dist + (ll)L.cnt * R.sum - (ll)R.cnt * L.sum;
   return res; 
}

void update(int x, int val) {
   int pos = x + offset; 
   t[pos].cnt += val;
   t[pos].sum += (ll)val * V[x];
   for (pos /= 2; pos; pos /= 2)
      t[pos] = merge(t[2 * pos], t[2 * pos + 1]);
}

node query(int x, int lo, int hi, int from, int to) {
   if (lo >= to || hi <= from) return node();
   if (lo >= from && hi <= to) return t[x];
   int mid = (lo + hi) / 2;
   return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int get(int val) {
   return lower_bound(V.begin(), V.end(), val) - V.begin();
}

void solve() {
   memcpy(y, x, sizeof y);
   for (int i = 0; i < N; i++)
      V.push_back(x[i]);
   for (int i = 0; i < M; i++) 
      if (type[i] == 1) {
         y[--a[i]] += b[i];
         V.push_back(y[a[i]]);
      }
      else {
         V.push_back(a[i]);
         V.push_back(b[i]);
      } 
   sort(V.begin(), V.end());
   
   for (int i = 0; i < N; i++) 
      t[get(x[i]) + offset] = node(1, x[i], 0);
   
   for (int i = offset - 1; i >= 0; i--)
      t[i] = merge(t[2 * i], t[2 * i + 1]);

   for (int i = 0; i < M; i++)
      if (type[i] == 1) {
        update(get(x[a[i]]), -1);
        x[a[i]] += b[i];
        update(get(x[a[i]]), 1); 
      }
      else printf("%I64d\n", query(1, 0, offset, get(a[i]), get(b[i]) + 1).dist);
}

int main() {
   load();
   solve();
   return 0;
}