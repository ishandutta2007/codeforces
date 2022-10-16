#include <iostream>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
char c[MAXN];
int l[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a] = true;
    }
    int ans = 0;
    l[0] = -1;
    for(int i = 1; i < MAXN; i++)
        l[i] = (c[i - 1]? i - 1 : l[i - 1]);
    for(int i = 2; i < MAXN; i++) {
        if(!c[i])
            continue;
        for(int j = 2 * i; j < MAXN; j += i)
            ans = max(ans, l[j] % i);
        ans = max(ans, l[MAXN - 1] % i);
    }
    cout << ans << '\n';
    return 0;
}