# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int t, n;
int a[NR];
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (int i = 1; i <= n * 2; i++) scanf("%d", a + i);
        sort(a + 1, a + n * 2 + 1);
        printf("%d\n", a[n + 1] - a[n]);
    }
    return 0;
}