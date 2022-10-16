#include <iostream>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int a[MAXN], ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++) {
        int j = i - 2, x = 1;
        while(true) {
            if(a[i] < a[j + 1])
                ans[x]++;
            if(!j)
                break;
            int nxt = (i - 2) / j + 1;
            if(a[i] < a[j + 1])
                ans[nxt]--;
            x = nxt;
            j = (i - 2) / x;
        }
    }
    for(int i = 1; i < n; i++)
        ans[i] += ans[i - 1];
    for(int i = 1; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}