#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

const int K = 2155, N = 200087;

struct Query {
  int l, r, idx, t;
  bool operator < (const Query &other) {
    if (l / K == other.l / K and r / K == other.r / K) return t < other.t;
    if (l / K == other.l / K) return r / K < other.r / K;
    return l / K < other.l / K;
  }
};

struct Event {
  int pos, from, to;
};

int nums[N], l = 0, r = -1;
int pos[N];
vector <int> input;

void add(int k) {
  int now = pos[k]++;
  nums[now+1]++;
  nums[now]--;
}

void sub(int k) {
  int now = pos[k]--;
  nums[now]--;
  nums[now-1]++;
}

void addEvent(Event e) {
  if (l <= e.pos and e.pos <= r) {
    add(e.to);
    sub(e.from);
  }
  input[e.pos] = e.to;
}

void subEvent(Event e) {
  if (l <= e.pos and e.pos <= r) {
    add(e.from);
    sub(e.to);
  }
  input[e.pos] = e.from;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q, a;
  cin >> n >> q;
  vector <Query> Q;
  vector <Event> E;
  input.resize(n);
  vector <int> v;
  fop (i,0,n) cin >> input[i], v.pb(input[i]);
  vector <int> aa = input;
  fop (i,0,q) {
    cin >> a;
    if (a == 1) {
      Query tmp;
      cin >> tmp.l >> tmp.r;
      tmp.l--; tmp.r--;
      tmp.idx = Q.size();
      tmp.t = E.size() - 1;
      Q.pb(tmp);
    } else {
      Event tmp;
      cin >> tmp.pos >> tmp.to;
      v.pb(tmp.to);
      tmp.pos--;
      tmp.from = aa[tmp.pos];
      aa[tmp.pos] = tmp.to;
      E.pb(tmp);
    }
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  fop (i,0,n) input[i] = lower_bound(v.begin(), v.end(), input[i]) - v.begin() + 1;
  fop (i,0,E.size()) {
    E[i].from = lower_bound(v.begin(), v.end(), E[i].from) - v.begin() + 1;
    E[i].to = lower_bound(v.begin(), v.end(), E[i].to) - v.begin() + 1;
  }
  sort(Q.begin(), Q.end());
  int t = -1;
  fop (i,0,N) pos[i] = 0;
  vector <int> anss(Q.size(), 1);
  fop (i,0,Q.size()) {
    while (r < Q[i].r) {
      r++;
      add(input[r]);
    }
    while (l > Q[i].l) {
      l--;
      add(input[l]);
    }
    while (r > Q[i].r) {
      sub(input[r]);
      r--;
    }
    while (l < Q[i].l) {
      sub(input[l]);
      l++;
    }
    while (t < Q[i].t) {
      t++;
      addEvent(E[t]);
    }
    while (t > Q[i].t) {
      subEvent(E[t]);
      t--;
    }

    fop (j,1,700) {
      if (nums[j]) {
        anss[Q[i].idx] = j + 1;
      } else {
        break;
      }
    }
  }
  fop (i,0,anss.size()) cout << anss[i] << '\n';
}