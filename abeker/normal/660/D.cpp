#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2005;

int N;
int x[MAXN], y[MAXN];
map <pii, int> cnt;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, y + i);
      
    long long sol = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            sol += cnt[pii(x[i] + x[j], y[i] + y[j])]++;
    
    printf("%I64d\n", sol);
    
    return 0;
}