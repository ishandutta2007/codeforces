#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

char abc[30];
int n, m, w;
vector<int> adj[404];
string minWord;
string ans;
int msk[222];
int allMsk = 0;

vector<pii> history;

void setMsk(int x, int color) {
    if (msk[x] == color)
        return;
    history.emplace_back(x, msk[x]);
    msk[x] = color;
}

void rollback(int top) {
    for (; sz(history) > top; ) {
        auto p = history.back();
        msk[p.X] = p.Y;
        history.pop_back();
    }
}

bool dfs(int x, int color) {
    if ((allMsk & 1 << color) == 0)
        return false;
    if (msk[x] == (1 << color))
        return true;
    int top = sz(history);
    setMsk(x, msk[x] | 1 << color);
    if (msk[x] == 3) {
        rollback(top);
        return false;
    }
    for (int y : adj[2 * x + msk[x] - 1]) {
        if (!dfs(y / 2, y % 2)) {
            rollback(top);
            return false;
        }
    }
    return true;
}

bool check() {
    REP (i, n) assert(msk[i] == 0);
    REP (i, n) {
        if (ans[i] - 'a' >= w) {
            rollback(0);
            return false;
        }
        int type = ans[i] == '?' ? -1 : (abc[ans[i] - 'a'] == 'C');
        if (type != -1) {
            if (!dfs(i, type)) {
                rollback(0);
                return false;
            }
        } else {
            if (!dfs(i, 0) && !dfs(i, 1)) {
                rollback(0);
                return false;
            }
        }
    }
    rollback(0);
    return true;
}

int main() {
    gets(abc);
    w = strlen(abc);
    REP (i, w) {
        if (abc[i] == 'V')
            allMsk |= 1;
        if (abc[i] == 'C')
            allMsk |= 2;
    }
    cin >> n >> m;
    REP (i, m) {
        int p1, p2;
        char t1, t2;
        cin >> p1 >> t1 >> p2 >> t2;
        p1 = (p1 - 1) * 2 + (t1 == 'C');
        p2 = (p2 - 1) * 2 + (t2 == 'C');
        adj[p1].pb(p2);
        adj[p2 ^ 1].pb(p1 ^ 1);
    }
    cin >> minWord;
    ans = minWord;
    if (check()) {
        cout << ans << endl;
        return 0;
    }
    for (int k = n - 1; k >= 0; --k) {
        fill(all(ans), '?');
        REP (i, k) {
            ans[i] = minWord[i];
        }
        ans[k] = minWord[k];
        int was = 0;
        for (; (++ans[k] - 'a') < w; ) {
            int type = 1 << (abc[ans[k] - 'a'] == 'C');
            if (was & type)
                continue;
            was |= type;
            if (check())
                break;
        }
        if (ans[k] - 'a' < w) {
            for (; ++k < n; ) {
                int was = 0;
                for (ans[k] = 'a'; ; ++ans[k]) {
                    int type = 1 << (abc[ans[k] - 'a'] == 'C');
                    if (was & type)
                        continue;
                    was |= type;
                    if (check())
                        break;
                }
            }
            assert(check());
            cout << ans << endl;
            return 0;
        }
    }
    puts("-1");
    return 0;
}