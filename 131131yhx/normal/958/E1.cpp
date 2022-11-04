#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

typedef long long ll;

int n, m;

int X[15][15][15][15], A[15][2], B[15][2];

ll cross(int a[2], int b[2], int c[2]) {
    return a[0] - b[0] * (c[1] - b[1]) - (a[1] - b[1]) * (c[0] - b[0]);
}
int calc(int a[2], int b[2], int c[2], int d[2]) {
    return cross(a, b, c) * cross(a, b, d) < 0 && cross(c, d, a) * cross(c, d, b) < 0;
}

int O[11];
#undef int
int main(){
#define int long long
    scanf("%lld%lld", &n, &m);
    if(n != m) {
        puts("No");
        return 0;
    }
    for(int i = 1; i <= n; i++) scanf("%lld%lld", &A[i][0], &A[i][1]);
    for(int i = 1; i <= m; i++) scanf("%lld%lld", &B[i][0], &B[i][1]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 1; k <= n; k++)
                for(int l = 1; l <= m; l++)
                    X[i][j][k][l] = calc(A[i], B[j], A[k], B[l]);
    for(int i = 1; i <= n; i++) O[i] = i;
    do {
        int flag = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                if(X[i][O[i]][j][O[j]]) {
                    flag = 1;
                    break;
                }
        if(!flag) {
            puts("Yes");
            return 0;
        }
    } while(next_permutation(O + 1, O + n + 1));
    puts("No");
    return 0;
}