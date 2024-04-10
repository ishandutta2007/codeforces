#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
const int offset = 1 << 18;
const ll INF = 1e18;
const int LOG = 19;

struct Node {
  int cnt;
  ll sum, mini;
  Node(int cnt, ll sum, ll mini) : cnt(cnt), sum(sum), mini(mini) {}
  Node() : cnt(0), sum(0), mini(INF) {}
};

int N, Q;
pii shirt[MAXN];
int price[MAXN];
pii byPrice[MAXN];
ll budget[MAXN];
int pos[MAXN], ans[MAXN];
Node tour[2 * offset];
set <int> small;
int ptr;

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &shirt[i].second, &shirt[i].first);
    shirt[i].first *= -1;
  }
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++)
    scanf("%lld", budget + i);
}

Node merge(Node l, Node r) {
  return Node(l.cnt + r.cnt, l.sum + r.sum, min(l.mini, l.sum + r.mini));
}

inline void refresh(int x) {
  tour[x] = merge(tour[2 * x], tour[2 * x + 1]);
}

void change(int x) {
  small.erase(x);
  tour[x + offset] = Node(0, 0, price[x]);
  for (x += offset, x /= 2; x; x /= 2)
    refresh(x);
}

pair <int, Node> get_first(int from, int val, bool isSum) {
  Node curr;
  int len = offset - from;
  for (int i = 0; i < LOG; i++) 
    if (len >> i & 1) {
      int x = offset + from >> i;
      Node nxt = merge(curr, tour[x]);
      auto check = [&](Node left) -> bool {
        return (isSum && left.sum > val) || (!isSum && left.mini <= val);
      };
      if (check(nxt)) {
        val -= curr.sum;
        while (x < offset) {
          x <<= 1;
          if (!check(tour[x])) {
            curr = merge(curr, tour[x]);
            val -= tour[x].sum;
            x ^= 1;
          }
        }
        return {x - offset, merge(curr, tour[x])};
      }
      from += 1 << i;
      curr = nxt;
    }
  return {offset - 1, curr};
}

pair <int, pair <int, ll>> first_sum(int from, int val) {
  pair <int, Node> tmp = get_first(from, val, true);
  return {*(--small.lower_bound(tmp.first)) + 1, tmp.first < N ? make_pair(tmp.second.cnt - 1, tmp.second.sum - price[tmp.first]) 
                                                               : make_pair(tmp.second.cnt, tmp.second.sum)};
}

pair <int, pair <int, ll>> first_mini(int from, int val) {
  pair <int, Node> tmp = get_first(from, val, false);
  return {tmp.first + 1, {tmp.second.cnt + (tmp.first < N), tmp.second.mini}};
}

void move_ptr(int val) {
  for (; ptr < N && byPrice[ptr].first > val; ptr++) 
    change(byPrice[ptr].second);
}

void solve() {
  sort(shirt, shirt + N);
  for (int i = 0; i < N; i++) {
    price[i] = shirt[i].second;
    byPrice[i] = {price[i], i};
  }
  sort(byPrice, byPrice + N, greater <pii> ());
  for (int i = 0; i < N; i++) {
    tour[i + offset] = Node(1, price[i], INF);
    small.insert(i);
  }
  for (int i = offset - 1; i >= 0; i--)
    refresh(i);
  auto cmp = [](int x, int y) { 
    return budget[x] < budget[y]; 
  };
  priority_queue <int, vector <int>, decltype(cmp)> events(cmp);
  for (int i = 0; i < Q; i++)
    events.push(i);
  small.insert(-1);
  small.insert(offset);
  while (!events.empty()) {
    int curr = events.top();
    events.pop();
    if (budget[curr] <= 0 || pos[curr] >= N)
      continue;
    move_ptr(budget[curr] / 2);
    pair <int, pair <int, ll>> option1 = first_sum(pos[curr], budget[curr]);
    pair <int, pair <int, ll>> option2 = first_mini(pos[curr], budget[curr]);
    if (option1.first > option2.first || option1.first <= pos[curr])
      swap(option1, option2);
    budget[curr] -= option1.second.second;
    ans[curr] += option1.second.first;
    pos[curr] = option1.first;
    events.push(curr);
  }
  for (int i = 0; i < Q; i++)
    printf("%d ", ans[i]);
  puts("");
}

int main() {
  load();
  solve();  
  return 0;
}