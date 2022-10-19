#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N, K;
char s[MAXN];
int pref[MAXN];

int sum(int lo, int hi) {
    return pref[min(hi, N)] - pref[max(lo, 1) - 1];
}

bool check(int dist) {
    for (int i = 1; i <= N; i++) 
        if (s[i] == '0' && sum(i - dist, i - 1) + sum(i + 1, i + dist) >= K)
            return true;
    return false;
}

int main() {
    scanf("%d%d%s", &N, &K, s + 1);
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] + (s[i] == '0');
    
    int lo = 0, hi = N;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    
    printf("%d\n", lo);
    
    return 0;
}