# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 105;
int t, n, s, ans;
int a[NR];
int main(){
    scanf("%d", &t);
    while (t--){
        s = 0;
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", a + i);
            if (a[i] == 0){
                ans++;
                s++;
            }
            s += a[i];
        }
        ans += s == 0;
        printf("%d\n", ans);
    }
    return 0;
}