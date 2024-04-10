#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int N;
int a[MAXN], b[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    for (int i = 0; i < N; i++)
        scanf("%d", b + i);
    
    int sol = 0;   
    for (int i = 0; i < N; i++) {
        int x = 0, y = 0;
        for (int j = i; j < N; j++) {
            x |= a[j];
            y |= b[j];
        }
        sol = max(sol, x + y);
    }
    
    printf("%d\n", sol);
    
    return 0;
}