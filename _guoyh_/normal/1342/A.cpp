# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
ll a, b, x, y;
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        ll ans = 0;
        if (x > y) swap(x, y);
        if (2 * a > b) ans = x * b + (y - x) * a;
        else ans = (x + y) * a;
        printf("%lld\n", ans);
    }
    return 0;
}