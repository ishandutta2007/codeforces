# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
int t, n;
int a[NR];
bool check(int x){
    int l = 0, r = 1000000000;
    for (int i = 2; i <= n; i++){
        if (a[i] == -1){
            if (a[i - 1] == -1) continue;
            l = max(l, a[i - 1] - x);
            r = min(r, a[i - 1] + x);
        } else if (a[i - 1] == -1){
            l = max(l, a[i] - x);
            r = min(r, a[i] + x);
        } else if (abs(a[i] - a[i - 1]) > x) return false;
    }
    return l <= r;
}
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        int lft = 0, rgt = 1000000000, ans;
        while (lft <= rgt){
            int mid = (lft + rgt) >> 1;
            if (check(mid)){
                ans = mid;
                rgt = mid - 1;
            } else lft = mid + 1;
        }
        int l = 0, r = 1000000000;
        for (int i = 2; i <= n; i++){
            if (a[i] == -1){
                if (a[i - 1] == -1) continue;
                l = max(l, a[i - 1] - ans);
                r = min(r, a[i - 1] + ans);
            } else if (a[i - 1] == -1){
                l = max(l, a[i] - ans);
                r = min(r, a[i] + ans);
            }
        }
        printf("%d %d\n", ans, l);
    }
    return 0;
}