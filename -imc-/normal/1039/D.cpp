#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

//#define int li

void solve(bool);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

    //while (true) solve(false);

    return 0;
}

int n;
vector<vector<int>> e;
vector<vector<int>> children;

int timer = 0;

int dfs(int v, int p) {
    //cout << "Dfs " << v << " " << p << endl;
    vector<int> childs;
    for (int u : e[v]) {
        if (u == p) continue;
        childs.push_back(dfs(u, v));
    }

    children.push_back(childs);
    return children.size() - 1;
}

vector<int> maxPathUp, answer;

int f(int k) {
    for (int v = 0; v < n; ++v) {
        int largest = 0, secondLargest = 0;
        answer[v] = 0;

        for (int u : children[v]) {
            answer[v] += answer[u];

            if (maxPathUp[u] > largest) {
                secondLargest = largest;
                largest = maxPathUp[u];
            } else if (maxPathUp[u] > secondLargest) {
                secondLargest = maxPathUp[u];
            }
        }

        if (largest + secondLargest + 1 >= k) {
            ++answer[v];
            maxPathUp[v] = 0;
        } else {
            maxPathUp[v] = largest + 1;
        }
    }

    return answer[n - 1];
}

vector<int> answers;

void fillAnswers(int l, int r) {
    if (l + 1 >= r) {
        return;
    }

    if (answers[l] == answers[r]) {
        for (int i = l + 1; i < r; ++i) {
            answers[i] = answers[l];
        }
        return;
    }

    int m = (l + r) / 2;
    answers[m] = f(m);

    fillAnswers(l, m);
    fillAnswers(m, r);
}

void solve(bool __attribute__((unused)) read) {
    cin >> n;

    e.resize(n);

    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    answer.assign(n, 0);
    maxPathUp.assign(n, 0);

    timer = 0;
    dfs(0, -1);

    for (int i = 0; i < n; ++i) {
        for (int x : children[i]) {
            assert(x < i);
        }
    }

    answers.resize(n + 1);
    int block = sqrt(n);
    block = max(block, 1);
    for (int i = 1; i <= min(n, block); ++i) {
        answers[i] = f(i);
    }
    answers[n] = f(n);
    if (block <= n) {
        fillAnswers(block, n);
    }

    for (int i = 1; i <= n; ++i) {
        cout << answers[i] << "\n";
    }
}