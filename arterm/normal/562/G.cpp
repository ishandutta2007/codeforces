#include <bits/stdc++.h>

using namespace std;

const int M = 133100;

int a[M], b[M], c[M], n;
int s[M];
bool used[M];

inline void add(int i, int sign) {
    s[a[i]] -= sign;
    s[b[i]] += sign;
    s[c[i]] += sign;
}

inline bool fit(int i) {
    add(i, 1);
    if (s[b[i]] > 5 || s[c[i]] > 5) {
        add(i, -1);
        return false;
    } else {
        return true;
    }
}

void check() {
    assert(false);
    for (int i = 1; i <= n; ++i)
        assert(s[i] <= 5);
}

void read() {
    scanf("%d", &n);
    for (int i = 1; i <= 4 * n; ++i) {
        scanf("%d%d%d", a + i, b + i, c + i);
    }
}

vector<int> ans;
int order[M];

void kill() {
    //check();
    for (int i = 1; i <= 4 * n; ++i)
        order[i] = i;
    random_shuffle(order + 1, order + (4 * n + 1));
    while((int) ans.size() < (4 * n))
        for (int J = 1; J <= 4 * n; ++J) {
            int j = order[J];
            if (!used[j] && fit(j)) {
                //check();
                used[j] = true;
                ans.push_back(j);
            }
        }
    printf("YES\n");
    for (int x : ans)
        printf("%d ", x);
    printf("\n");
}

int main() {
    //ios_base::sync_with_stdio(false);
    read();
    kill();
    return 0;
}