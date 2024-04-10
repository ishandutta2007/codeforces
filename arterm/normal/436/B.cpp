#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

using namespace std;

#define M 2014

int n, m, ans[M], k;
char f[M][M];

void read(void){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
        cin >> f[i][j];
}

void kill(void){
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j){
        if (f[i][j] == 'U'){
            if (i % 2 == 1)
                ++ans[j];
        }
        if (f[i][j] == 'L'){
            int x = j - (i - 1);
            if (x > 0)
                ++ans[x];
        }
        if (f[i][j] == 'R'){
            int x = j + (i - 1);
            if (x <= m)
                ++ans[x];
        }
    }
    for (int j = 1; j <= m; ++j, cout << " ")
        cout << ans[j];
    cout << "\n";
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    
    kill();

    return 0;
}