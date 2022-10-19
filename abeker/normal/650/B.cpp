#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 500005;

int N, A, B, T;
char s[MAXN];
int pref[MAXN];

void load() {
    scanf("%d%d%d%d%s", &N, &A, &B, &T, s + 1);
}

bool check(int right, int left) {
    return (pref[right] + pref[N] - pref[N - left]) * B + (left + right - 1 + min(left, right - 1)) * A + left + right <= T; 
}

int solve() {
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] + (s[i] == 'w');
        
    if (pref[1] + 1 > T) return 0;
    
    int sol = 0;
    for (int i = 1; i <= N; i++) {
        int lo = 0, hi = N - i;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check(i, mid)) lo = mid;
            else hi = mid - 1;
        }
        if (check(i, lo)) 
            sol = max(sol, i + lo);
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}