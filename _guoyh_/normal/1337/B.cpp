# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, s, n, m;
bool check(){
    for (int i = 1; i <= n; i++){
        if (s <= m * 10) return true;
        s = s / 2 + 10;
    }
    return s <= m * 10;
}
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d%d%d", &s, &n, &m);
        if (check()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}