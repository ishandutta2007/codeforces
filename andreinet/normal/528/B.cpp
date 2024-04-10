#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 200005;

pair<int, int> A[Nmax];
int Dp[Nmax];

vector<int> allValues, aib;

void Norm() {
    sort(allValues.begin(), allValues.end());
    allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
}

int getPos(int val) {
    return lower_bound(allValues.begin(), allValues.end(), val) - allValues.begin() + 1;
}

void update(int pos, int val) {
    for (; pos < int(aib.size()); pos += pos & -pos)
        aib[pos] = max(aib[pos], val);
}

int query(int pos) {
    int ret = 0;
    for (; pos > 0; pos -= pos & -pos) {
        ret = max(ret, aib[pos]);
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i].first >> A[i].second;
        allValues.push_back(A[i].first + A[i].second);
        allValues.push_back(A[i].first - A[i].second);
    }
    Norm();
    aib = vector<int>(allValues.size() + 4);

    sort(A + 1, A + N + 1);
    for (int i = 1; i <= N; ++i)  {
        Dp[i] = Dp[i - 1];
        int p1 = getPos(A[i].first - A[i].second), p2 = getPos(A[i].first + A[i].second);
        int x = query(p1) + 1;
        Dp[i] = max(Dp[i], x);
        update(p2, Dp[i]);
    }

    cout << Dp[N] << '\n';
}