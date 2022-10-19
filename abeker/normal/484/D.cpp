#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 1000008;

int N;
int a[MAXN];
ll dp[MAXN];
vector <int> V;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

ll solve() {
    a[0] = a[N + 1] = (int)1e9 + 5;
    int cnt = 0;
    for (int i = 1; i <= N + 1; i++) {
        if (a[i] != a[i - 1]) {
            if (cnt) V.push_back(a[i - 1]);
            if (cnt > 1) V.push_back(a[i - 1]);
            cnt = 0;
        }
        cnt++;
    }
    N = V.size();
    for (int i = 0; i < V.size(); i++) 
        a[i + 1] = V[i];
        
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        if (a[i] == a[i - 1]) continue;
        if (a[i] > a[i - 1]) {
            bool ok = true;
            for (int j = 1; j < 12 && j < i; j++) {
                if (a[i - j] > a[i - j + 1]) { ok = false; break; }
                dp[i] = max(dp[i], dp[i - j - 1] + a[i] - a[i - j]);
            }
            if (ok && i > 1) dp[i] = max(dp[i], dp[i - 1] + a[i] - a[i - 1]);
        }
        else {
            bool ok = true;
            for (int j = 1; j < 12 && j < i; j++) {
                if (a[i - j] < a[i - j + 1]) { ok = false; break; }
                dp[i] = max(dp[i], dp[i - j - 1] + a[i - j] - a[i]);
            }
            if (ok && i > 1) dp[i] = max(dp[i], dp[i - 1] + a[i - 1] - a[i]);
        }
    }
        
    return dp[N];
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}