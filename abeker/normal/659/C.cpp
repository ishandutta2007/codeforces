#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 100005;

int N, M;
int a[MAXN];
map <int, bool> has;

int main() {
    scanf("%d%d", &N, &M);
    while (N--) {
        int x;
        scanf("%d", &x);
        has[x] = true;
    }
    
    vector <int> sol;
    for (int i = 1; i < 2 * MAXN; i++)
        if (!has[i]) {
            if (i > M) break;
            M -= i;
            sol.push_back(i);
        }
    
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d ", sol[i]);
    puts("");
    
    return 0;
}