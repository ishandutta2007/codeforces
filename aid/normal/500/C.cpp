#include <iostream>

using namespace std;

const int MAXN = 505, MAXM = 1005;
int w[MAXN], b[MAXM];
char used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            used[j] = false;
        used[b[i]] = true;
        for(int j = i + 1; j < m; j++) {
            if(b[j] == b[i])
                break;
            if(!used[b[j]]) {
                ans += w[b[i]];
                used[b[j]] = true;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}