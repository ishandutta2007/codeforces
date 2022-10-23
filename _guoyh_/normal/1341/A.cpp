# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, n, a, b, c, d;
int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
        if ((a + b) * n >= (c - d) && (a - b) * n <= (c + d)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}