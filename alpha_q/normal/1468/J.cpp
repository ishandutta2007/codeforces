#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int id[sz], r[sz];

struct node {
   int u, v, cost;
};

vector <node> edges;
vector <int> trees;

bool cmp(node a, node b) {
   return a.cost < b.cost;
}

int root(int x) {
   while(id[x] ^ x) x = id[x];
   return x;
}

int main() {
   int t;
   cin >> t;
   while(t--) {
      int n, m, k;
      scanf("%d %d %d", &n, &m, &k);

      edges.clear();
      while(m--) {
         int u, v, c;
         scanf("%d %d %d", &u, &v, &c);
         struct node e = {u, v, c};
         edges.push_back(e);
      }
      sort(edges.begin(), edges.end(), cmp);

      for(int i=1; i<=n; i++) id[i]=i, r[i]=1;

      trees.clear();
      for(auto p : edges) {
         int x = root(p.u);
         int y = root(p.v);
         if(x ^ y) {
            trees.push_back(p.cost);

            if(r[x]<r[y])
               id[x]=id[y], r[y]+=r[x];
            else
               id[y]=id[x], r[x]+=r[y];
         }
      }

      ll ans = 0;
      bool yes = 0;
      for(int x : trees) if(x >= k) ans += x - k, yes = 1;

      if(yes) {
         printf("%lld\n", ans);
         continue;
      }

      ans = LLONG_MAX;
      for(auto e : edges) ans = min(ans, (ll)abs(e.cost - k));
      printf("%lld\n", ans);
   }
}