#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;
const int INF = (int)1e9 + 41;
//const ll INF = (ll)1e18 + 41;

struct Pt {
    pair <int, int> st;
    pair <int, int> en;
} a[N];

bool cmp(Pt a, Pt b) {
    if (a.en.first != b.en.first)
        return a.en.first > b.en.first;
    return a.en.second < b.en.second;
}

int dist(pair <int, int> a, pair <int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

vector <Pt> answer;

bool isEmpty(int x, int y, int m) {
    for (int i = 0; i < m; ++i)
        if (a[i].st.first == x && a[i].st.second == y)
            return false;
    return true;
}

void print() {
    cout << answer.size() << endl;
    for (auto t: answer)
        cout << t.st.first + 1 << " " << t.st.second + 1 << " " << t.en.first + 1 << " " << t.en.second + 1 << endl;
    exit(0);
}

void solve_min(int n, int m) {
    int u[10][10];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            u[i][j] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        int xx, yy;
        cin >> xx >> yy;
        u[xx][yy] = i;
    }
    int x[10], y[10];
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }

    vector<pair<pair<int, int>, pair<int, int>>> ans;
    while (true) {
        bool ok = true;
        for (int i = 0; i < m; i++) {
            if (u[x[i]][y[i]] != i) ok = false;
        }
        if (ok) break;

        int x1 = rand() % n + 1;
        int y1 = rand() % n + 1;
        int x2 = rand() % n + 1;
        int y2 = rand() % n + 1;
        if (abs(x1 - x2) + abs(y1 - y2) != 1) continue;
        if (u[x1][y1] != -1 && u[x2][y2] == -1) {
            u[x2][y2] = u[x1][y1];
            u[x1][y1] = -1;
            ans.push_back({{x1, y1}, {x2, y2}});
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        auto q = ans[i];
        cout << q.first.first << " " << q.first.second << " " << q.second.first << " " << q.second.second << "\n";
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (n <= 2) {
        solve_min(n, m);
        exit(0);
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i].st.first >> a[i].st.second;
        a[i].st.first--;
        a[i].st.second--;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i].en.first >> a[i].en.second;
        a[i].en.first--;
        a[i].en.second--;
    }

    for (int i = 0; i < m; i++) { // into first row
        int nearNum = -1;
        if (!isEmpty(0, i, m))
            continue;
        for (int j = 0; j < m; j++)
            if (a[j].st.first) {
                if (nearNum == -1 || dist({0, i}, a[nearNum].st) > dist({0, i}, a[j].st))
                    nearNum = j;
            }
        //assert(nearNum != -1);
        while (a[nearNum].st.second > i) { // right
            answer.push_back({a[nearNum].st, {a[nearNum].st.first, a[nearNum].st.second - 1}});
            a[nearNum].st.second--;
        }
        while (a[nearNum].st.second < i) { // left
            answer.push_back({a[nearNum].st, {a[nearNum].st.first, a[nearNum].st.second + 1}});
            a[nearNum].st.second++;
        }
        while (a[nearNum].st.first > 0) { // up
            answer.push_back({a[nearNum].st, {a[nearNum].st.first - 1, a[nearNum].st.second}});
            a[nearNum].st.first--;
        }
    }

    for (int i = 0; i < m; i++) {
        answer.push_back({a[i].st, {a[i].st.first + 1, a[i].st.second}});
        a[i].st.first++;
        answer.push_back({a[i].st, {a[i].st.first + 1, a[i].st.second}});
        a[i].st.first++;
    }

    sort(a, a + m, cmp);

    for (int i = 0; i < m; i++) {
        answer.push_back({a[i].st, {a[i].st.first - 1, a[i].st.second}});
        a[i].st.first--;
        while (a[i].st.second > i) { // right
            answer.push_back({a[i].st, {a[i].st.first, a[i].st.second - 1}});
            a[i].st.second--;
        }
        while (a[i].st.second < i) { // left
            answer.push_back({a[i].st, {a[i].st.first, a[i].st.second + 1}});
            a[i].st.second++;
        }
        answer.push_back({a[i].st, {a[i].st.first - 1, a[i].st.second}});
        a[i].st.first--;
    }

    for (int i = 0; i < m; i++) { // down to end row
        while (a[i].st.first < a[i].en.first) {
            answer.push_back({a[i].st, {a[i].st.first + 1, a[i].st.second}});
            a[i].st.first++;
        }
    }

    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        vector <int> nums;
        while (cur < m && a[cur].en.first == i) {
            nums.push_back(cur);
            cur++;
        }
        if (nums.size()) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int i1 = 0; i1 < (int)nums.size(); i1++) {
                    int i = nums[i1];
                    while (a[i].st.second < a[i].en.second && (i1 + 1 == (int)nums.size() || a[i].st.second + 1 < a[i + 1].st.second)) {
                        answer.push_back({a[i].st, {a[i].st.first, a[i].st.second + 1}});
                        a[i].st.second++;
                    }
                    if (a[i].st.second > a[i].en.second && (i1 == 0 || a[i].st.second - 1 > a[i - 1].st.second)) {
                        answer.push_back({a[i].st, {a[i].st.first, a[i].st.second - 1}});
                        a[i].st.second--;
                    }
                }
            }
        }
    }
    print();
}

int main() {

    //freopen("a.in", "r", stdin);
    //solve();
    solve();
}