#include <iostream>

using namespace std;

const int MAXN = 2005;
int ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if(c == 'L') {
                if(j - i >= 0)
                    ans[j - i]++;
            }
            else if(c == 'R') {
                if(j + i < m)
                    ans[j + i]++;
            }
            else if(c == 'U' && !(i & 1))
                ans[j]++;
        }
    for(int i = 0; i < m; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}