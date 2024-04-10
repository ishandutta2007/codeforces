#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <bitset>
#include <string>

using namespace std;

typedef long long ll;

int n, q, A[555555], F[555555], L[555555], R[555555];

int getf(int x) {return F[x] == x ? x : F[x] = getf(F[x]);}

int main() {
    scanf("%d%d", &n, &q);
    int all_0 = 1;
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for(int i = 1; i <= n; i++) if(A[i] != 0) all_0 = 0;
    for(int i = 1; i <= n; i++) if(A[i] > q) {
        puts("NO");
        return 0;
    }
    if(all_0) {
        puts("YES");
        for(int i = 1; i <= n; i++) printf("%d ", q);
        putchar('\n');
        return 0;
    }
    for(int i = 1; i <= n + 1; i++) F[i] = i;
    for(int i = 1; i <= n; i++) if(L[A[i]] == 0) L[A[i]] = i;
    for(int i = n; i >= 1; i--) if(R[A[i]] == 0) R[A[i]] = i;
    if(!L[q]) {
        for(int i = 1; i <= n; i++) if(A[i] == 0) {
            A[i] = q;
            L[q] = i;
            R[q] = i;
            break;
        }
        if(!L[q]) {
            puts("NO");
            return 0;
        }
    }
    for(int i = q; i >= 1; i--) if(L[i]) {
        int l = L[i], r = R[i];
        while(l > 1 && A[l - 1] == 0) A[--l] = i;
        while(r < n && A[r + 1] == 0) A[++r] = i;
        for(int j = getf(l); j <= r; j = getf(j)) {
            if(A[j] == 0) A[j] = i;
            else if(A[j] != i) {
                puts("NO");
                return 0;
            }
            F[j] = j + 1, j++;
        }
    }
    for(int i = 1; i <= n; i++) if(!A[i]) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i = 1; i <= n; i++) printf("%d ", A[i]);
    putchar('\n');
    return 0;
}