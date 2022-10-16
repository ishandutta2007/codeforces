#include <bits/stdc++.h>

using namespace std;

int N, K;

const int NMAX = 100000 + 5;
int v[NMAX];

int aib[NMAX];

inline int lsb(int node) {
    return node & (-node);
}

void init() {
    for (int i = 1; i <= N; ++ i) {
        aib[i] = 1;
        for (int j = i - lsb(i) + 1; j <= i; ++ j)
            aib[i] = (1LL * aib[i] * v[j]) % K;
    }
}

int query(int l, int r) {
    int ans = 1;
    while (r >= l) {
        if (r - lsb(r) + 1 >= l) {
            ans = (1LL * ans * aib[r]) % K;
            r -= lsb(r);
        }
        else {
            ans = (1LL * ans * v[r]) % K;
            r --;
        }
    }
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    init();

    long long int ans = 0;

    int l = 0;
    for (int i = 1; i <= N; ++ i) {
        while (l + 1 <= i && query(l + 1, i) == 0)
            ++ l;
        ans += l;
    }

    cout << ans << '\n';
    return 0;
}