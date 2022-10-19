#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char color[] = "RGBYW";

int N;
int cnt[5][5];
int tmp[5][5];

void load() {
    scanf("%d", &N);
    while (N--) {
        char s[5];
        scanf("%s", s);
        cnt[strchr(color, s[0]) - color][s[1] - '1']++; 
    }
}

inline int bc(int x) {
    return __builtin_popcount(x);
}

bool check(int a, int b) {
    memcpy(tmp, cnt, sizeof tmp);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (a >> i & 1 && b >> j & 1)
                tmp[i][j] = 0;
    
    for (int i = 0; i < 5; i++) 
        if (a >> i & 1) {
            int k = 0;
            for (int j = 0; j < 5; j++)
                if (tmp[i][j]) {
                    tmp[i][j] = 0;
                    k++;
                }
            if (k > 1) return false;
        }
    
    for (int j = 0; j < 5; j++)
        if (b >> j & 1) {
            int k = 0;
            for (int i = 0; i < 5; i++)
                if (tmp[i][j]) {
                    tmp[i][j] = 0;
                    k++;
                }
            if (k > 1) return false;
        }
    
    int k = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (!(a >> i & 1) && !(b >> j & 1) && tmp[i][j])
                k++;
                
    return k < 2;     
}

int solve() {
    int sol = 10;
    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 32; j++)    
            if (check(i, j)) 
                sol = min(sol, bc(i) + bc(j));
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}