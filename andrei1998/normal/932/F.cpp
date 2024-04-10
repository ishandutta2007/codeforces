#include <bits/stdc++.h>
 
using namespace std;
 
class Batch {
public:
    using T = long long;
    const long double EPS = 1E-20L;
 
    struct SetElem {
        T a, b;
        mutable const SetElem* next = nullptr;
 
        bool is_query;
 
        SetElem(T query_x) : b(query_x), is_query(true) {}
        SetElem(T a, T b) : a(a), b(b), is_query(false) {}
 
        T eval(T x) const { return a * x + b; }
 
        bool operator< (const SetElem &rhs) const {
            assert(!rhs.is_query);
            if (is_query) {
                if (rhs.next == nullptr) return true;
                return rhs.eval(b) > rhs.next->eval(b);
            } else return (a != rhs.a) ? a < rhs.a : b < rhs.b;
        }
    };
 
    set<SetElem> data;
 
    bool is_bad(set<SetElem>::iterator it) {
        if (it == data.begin() || next(it) == data.end())
            return false;
 
        auto prv = prev(it), nxt = next(it);
        return 1.0L * (it->b - prv->b) * (nxt->a - it->a)
            <= 1.0L * (it->b - nxt->b) * (prv->a - it->a) + EPS;
    }
 
    void erase(set<SetElem>::iterator it) {
        if (it != data.begin())
            prev(it)->next = it->next;
        data.erase(it);
    }
    void Insert(T slope, T intercept) {
        auto p = data.insert(SetElem(slope, intercept));
        if (!p.second) return;
 
        auto it = p.first;
        if (it != data.begin()) prev(it)->next = &(*it);
        if (next(it) != data.end()) it->next = &(*next(it));
 
        if (is_bad(it)) erase(it);
        else {
            while (it != data.begin()) {
                auto prv = prev(it);
                if (is_bad(prv)) {
                    erase(prv);
                } else break;
            }
            while (next(it) != data.end()) {
                auto nxt = next(it);
                if (is_bad(nxt)) {
                    erase(nxt);
                } else break;
            }
        }
    }
 
    T EvaluateMax(T x) {
        SetElem ret(x);
        auto it = data.upper_bound(ret);
        return it->eval(x);
    }
};
 
typedef long long int lint;
const int NMAX = 100000 + 5;
 
vector <int> tree[NMAX];
int a[NMAX];
int b[NMAX];
lint dp[NMAX];
 
Batch *sets[NMAX];
 
void moveAll(Batch &a, Batch &b) {
    for (const auto &it: a.data)
        b.Insert(it.a, it.b);
    a.data.clear();
}
 
int sz[NMAX];
void dfs(int node, int father) {
    if (father)
        tree[node].erase(find(tree[node].begin(), tree[node].end(), father));
 
    sz[node] = 1;
    if (tree[node].empty()) {
        dp[node] = 0;
        sets[node] = new Batch;
    }
    else {
        int who = 0;
        for (auto it: tree[node]) {
            dfs(it, node);
            if (sz[it] > sz[who])
                who = it;
        }
 
        for (auto it: tree[node])
            if (it != who)
                moveAll(*sets[it], *sets[who]);
 
        sets[node] = sets[who];
        dp[node] = -sets[node] -> EvaluateMax(a[node]);
    }
 
    sets[node] -> Insert(-b[node], -dp[node]);
}
 
int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
 
    int N;
    cin >> N;
 
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];
    for (int i = 1; i <= N; ++ i)
        cin >> b[i];
 
    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
 
    dfs(1, 0);
    for (int i = 1; i <= N; ++ i)
        cout << dp[i] << " \n"[i == N];
    return 0;
}