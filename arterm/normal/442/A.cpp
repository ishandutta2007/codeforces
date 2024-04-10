#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 13

int get(char ch){
    if (ch == 'R')
        return 0;
    if (ch == 'G')
        return 1;
    if (ch == 'B')
        return 2;
    if (ch == 'Y')
        return 3;
    return 4;
}

bool u[M][M];
bool x[M], y[M];

void read(){
    int n;
    cin >> n;
    char x, y;
    for (int i = 0; i < n; ++i){
        cin >> x >> y;
        u[get(x)][y - '1'] = true;
    }
}

bool cover(int mask){
    for (int i = 0; i < 5; ++i)
        x[i] = y[i] = false;

    for (int i = 0; i < 5; ++i)
    if (mask & (1 << i))
        x[i] = true;

    for (int i = 0; i < 5; ++i)
    if (mask & (1 << (i + 5)))
        y[i] = true;

    bool flag = true;

    for (int x1 = 0; x1 < 5; ++x1)
    for (int y1 = 0; y1 < 5; ++y1)
    for (int x2 = 0; x2 < 5; ++x2)
    for (int y2 = 0; y2 < 5; ++y2)
    if (x1 != x2 || y1 != y2)
    if (u[x1][y1] && u[x2][y2]){
        if (x1 != x2)
        if (x[x1] || x[x2])
            continue;
        if (y1 != y2)
        if (y[y1] || y[y2])
            continue;
        flag = 0;
    }

    return flag;
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    
    int ans = 13;

    for (int i = 0; i < 1024; ++i)
    if (cover(i)){
        int j = 0;
        for (int k = 0; k < 10; ++k)
        if (i & (1 << k))
            ++j;
        ans = min(ans, j);
    }
    
    cout << ans << "\n";

    return 0;
}