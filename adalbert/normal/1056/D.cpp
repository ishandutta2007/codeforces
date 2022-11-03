#include <bits/stdc++.h>
#define int ll
#define fir first
#define sec second
#define pb push_back
using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 100;
int answer;

int sum[MAX_N];
vector<int> sons, vec[MAX_N];
void solve(int u) {
    if (vec[u].empty())
        sum[u] = 1;

    for (auto i:vec[u]) {
            solve(i);
            sum[u] += sum[i];
        }

    sons.pb(sum[u]);
}

main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        vec[p].pb(i);
    }

    solve(1);

    sort(sons.begin(), sons.end());

    for (auto i:sons)
        cout << i << ' ';
}