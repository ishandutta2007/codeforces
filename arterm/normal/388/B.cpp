#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define M 2010

int n = 2;
bool u[M][M];

void add(int x, int y){
    u[x][y] = u[y][x] = 1;
}

void write(void){
    cout << n << "\n";
    for (int i = 1; i <= n; ++i, cout << "\n")
    for (int j = 1; j <= n; ++j)
        cout << (u[i][j] ? 'Y' : 'N');
}

void add(int x, int y, int len){
    if (len == 1){
        add(x, y);
        return;
    }
    add(x, n + 1);
    for (int i = 2; i < len; ++i)
        add(n+i-1, n + i); 
    add(n + len - 1, y);
    n += (len - 1);
}

int build(int x, int y, int k){
    if (k == 1){
        add(x, y);
        return 1;
    }
    ++n;
    int to = n;
    add(x, to, 2);
    add(x, to, 2);
    int w = build(to, y, k / 2);
    if (k % 2 == 1)
        add(x, y, w + 2);
    return w + 2;
}

void wrt1(void){
    for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
    if (u[i][j])
        cout << i << " " << j << "\n";
}

int main(){
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    int k;
    cin >> k;

    n = 2;

    build(1, 2, k);
    write();


    return 0;
}