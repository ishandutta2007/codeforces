#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cstdlib>

using namespace std;

int A[2010][2010], cnt = 0, n;

int Abs(int x) {return x < 0 ? -x : x;}

int ans = 0;

map <int, int> hsh;

void affect(int x, int y, int dep = 0) {
    if(!dep) cnt++;
    if(!dep && hsh[x * 10000 + y]) {cnt--; return;}else if(!dep) printf("%d %d\n", x, y);
    if(!dep) hsh[x * 10000 + y] = 1;
    if(cnt == n) {
        //printf("%d %d\n", ans, n * n / 10);
        exit(0);
    }
    /*if(A[x][y] >= 9999) return;
    A[x][y] = 9999;
    ans++;
    for(int i = -2; i <= 2; i++)
        for(int j = -2; j <= 2; j++)
            if(Abs(i) + Abs(j) == 3) {
                if(++A[x + i][y + j] >= 4) {
                    affect(x + i, y + j, dep + 1);
                }
            }*/
}

int main() {
    scanf("%d", &n);
    //for(int i = 1; i <= n / 2; i++) printf("%d %d\n", 1, i);
    //for(int i = 1; i <= n / 2 + n % 2; i++) printf("%d %d\n", 2, i);
    
    if(n <= 12) {
        for(int i = 1; i <= n / 2; i++) affect(100, 100 + i);
        for(int i = 1; i <= n / 2 + n % 2; i++) affect(101, 100 + i);
        return 0;
    }
    affect(1000, 1000);
    for(int i = 1; ; i++) affect(1000, 1000-i), affect(1000, 1000+i), affect(1000+i, 1000), affect(1000-i, 1000);
    printf("%d %d\n", ans, n * n / 10);//puts("NO");
    return 0;
}