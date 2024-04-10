#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 200005;

int N;
int a[MAXN];
ll pref[MAXN];
ld best_odd[MAXN], best_even[MAXN];
int opt_odd[MAXN], opt_even[MAXN];
vector <int> sol;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

ll sum(int l, int r) {
    return pref[r] - pref[l - 1];
}

ld calc_odd(int x, int k) {
    return (ld)(sum(x - k, x) + sum(N - k + 1, N)) / (2 * k + 1);
}

ld calc_even(int x, int k) {
    return (ld)(sum(x - k, x + 1) + sum(N - k + 1, N)) / (2 * k + 2);
}

void solve() {
    if (N == 1) {
        printf("1\n%d\n", a[1]);
        return;
    }
    
    sort(a + 1, a + N + 1);
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] + a[i];
    
    for (int i = 2; i < N; i++) {
        int lo = 0, hi = min(N - i, i - 1);
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (calc_odd(i, mid) > calc_odd(i, mid + 1)) hi = mid;
            else lo = mid + 1;
        }
        opt_odd[i] = lo;
        best_odd[i] = calc_odd(i, lo) - a[i];
    }        
    
    for (int i = 2; i < N - 1; i++) {
        int lo = 0, hi = min(N - i - 1, i - 1);
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (calc_even(i, mid) > calc_even(i, mid + 1)) hi = mid;
            else lo = mid + 1;
        }
        opt_even[i] = lo;
        best_even[i] = calc_even(i, lo) - (ld)(a[i] + a[i + 1]) / 2;
    }
    
    int maks_odd = max_element(best_odd + 1, best_odd + N + 1) - best_odd;
    int maks_even = max_element(best_even + 1, best_even + N + 1) - best_even;
    
    if (best_odd[maks_odd] > best_even[maks_even]) {
        for (int i = opt_odd[maks_odd]; i; i--) {
            sol.push_back(a[N + 1 - i]);
            sol.push_back(a[maks_odd - i]);
        }
        sol.push_back(a[maks_odd]);
    }
    else {
        for (int i = opt_even[maks_even]; i; i--) {
            sol.push_back(a[N + 1 - i]);
            sol.push_back(a[maks_even - i]);
        }
        sol.push_back(a[maks_even]);
        sol.push_back(a[maks_even + 1]);
    }
    
    sort(sol.begin(), sol.end());
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d ", sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}