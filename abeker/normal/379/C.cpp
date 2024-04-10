#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 300010;

int n, sol[MAXN];
pair <int, int> p[MAXN];

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    
    sort(p + 1, p + n + 1);
    
    for (int i = 1; i <= n; i++)
        sol[p[i].second] = max(sol[p[i - 1].second] + 1, p[i].first);
    
    for (int i = 1; i <= n; i++) 
        printf("%d ", sol[i]);
    puts("");
    
    return 0;
}