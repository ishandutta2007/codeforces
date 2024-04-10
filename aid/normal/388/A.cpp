#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int x[MAXN], a[MAXN], p[MAXN];
char used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x + n);
    int ans = 0;
    while(true) {
        for(int i = 0; i < n; i++) {
            a[i] = 0;
            p[i] = -1;
        }
        for(int i = 1; i < n; i++)
            if(!used[i])
                for(int j = 0; j < i; j++)
                    if(!used[j] && a[j] + 1 <= x[i] && a[j] + 1 > a[i]) {
                        a[i] = a[j] + 1;
                        p[i] = j;
                    }
        bool b = false;
        for(int i = n - 1; i >= 0; i--)
            if(!used[i]) {
                int j = i;
                while(j != -1) {
                    used[j] = true;
                    j = p[j];
                }
                b = true;
                break;
            }
        if(!b)
            break;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}