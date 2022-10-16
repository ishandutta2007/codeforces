#include <iostream>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans[a] = 1;
    }
    int maxAns = 0;
    for(int i = MAXN - 1; i >= 0; i--) {
        if(!ans[i])
            continue;
        for(int j = 2 * i; j < MAXN; j += i)
            ans[i] = max(ans[i], ans[j] + 1);
        maxAns = max(maxAns, ans[i]);
    }
    cout << maxAns << '\n';
    return 0;
}