#include <bits/stdc++.h>
#define MAX 1024
using namespace std;

int a[MAX][MAX];
int n, m, q, x, y, counter, ans;
int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < q; i++){
        ans = 0;
        cin >> x >> y;
        a[x][y] = (a[x][y] == 0 ? 1 : 0);
        for(int i = 1; i <= n; i++){
            counter = 0;
            for(int j = 1; j <= m; j++){
                counter = (a[i][j] == 1 ? counter + 1 : 0);
                ans = max(ans, counter);
            }
            ans = max(counter, ans);
        }
        cout << ans << endl;
    }
}