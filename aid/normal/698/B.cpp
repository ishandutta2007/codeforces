#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int p[MAXN];
char used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    int root = -1;
    for(int i = 0; i < n; i++)
        if(p[i] == i) {
            root = i;
            break;
        }
    int ans = 0;
    if(root == -1) {
        root = 0;
        while(!used[root]) {
            used[root] = 2;
            root = p[root];
        }
        p[root] = root;
        ans++;
    }
    used[root] = 2;
    for(int i = 0; i < n; i++)
        if(!used[i]) {
            int x = i;
            while(!used[x]) {
                used[x] = 1;
                x = p[x];
            }
            int y = -1;
            if(used[x] == 1)
                y = x;
            x = i;
            while(used[x] != 2) {
                used[x] = 2;
                x = p[x];
            }
            if(y != -1) {
                p[y] = root;
                ans++;
            }
        }
    cout << ans << '\n';
    for(int i = 0; i < n; i++)
        cout << p[i] + 1 << ' ';
    cout << '\n';
    return 0;
}