#include <iostream>

using namespace std;

const int MAXN = 55;
int a[MAXN][MAXN], ans[MAXN];
char used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    for(int i = 0; i < n; i++) {
        int x = -1;
        for(int j = 0; j < n; j++) {
            bool ok = true;
            for(int k = 0; k < n; k++)
                if(k != j && !used[k] && a[j][k] != i) {
                    ok = false;
                    break;
                }
            if(ok) {
                x = j;
                break;
            }
        }
        used[x] = true;
        ans[x] = i;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}