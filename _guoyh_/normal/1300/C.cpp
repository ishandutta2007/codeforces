# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int n, mx = -1, mn;
int a[NR], f[NR], b[NR];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    f[0] = b[n + 1] = ~0;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] & (~a[i]);
    for (int i = n; i >= 1; i--) b[i] = b[i + 1] & (~a[i]);
    for (int i = 1; i <= n; i++){
        if ((a[i] & f[i - 1] & b[i + 1]) > mx){
            mx = (a[i] & f[i - 1] & b[i + 1]);
            mn = i;
        }
    }
    printf("%d ", a[mn]);
    for (int i = 1; i <= n; i++)
        if (i != mn) printf("%d ", a[i]);
    putchar('\n');
    return 0;
}