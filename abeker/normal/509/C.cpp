#include <cstdio>
using namespace std;

const int MAXN = 405;

int N;
int a[MAXN], b[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", b + i);
}

void fill(int sum, int l) {
    for (int i = 0; i < l; i++)
        a[i] = 0;
    for (int i = 0; i < sum / 9; i++)
        a[i] = 9;
    a[sum / 9] = sum % 9; 
}

int f(int x) {
    return (x + 8) / 9;
}

void output(int l) {
    for (int i = l - 1; i >= 0; i--)
        printf("%d", a[i]);
    puts("");
}

void solve() {
    int len = 0;
    for (int i = 1; i <= N; i++) {
        int tmp = f(b[i]);
        if (tmp > len) {
            fill(b[i], tmp);
            len = tmp;
        }
        else {
            int pref = 0;
            bool ok = false;
            for (int j = 0; j < len && !ok; j++) {
                for (int k = a[j] + 1; k < 10 && !ok; k++) {
                    int curr = b[i] - b[i - 1] + pref - k + a[j];
                    if (curr >= 0 && f(curr) <= j) {
                        fill(curr, j);
                        a[j] = k;
                        ok = true;
                    }
                }
                pref += a[j];
            }
            if (!ok) {
                fill(b[i] - 1, len);
                a[len++] = 1;
            }
        } 
        output(len);
    }
}

int main() {
    load();
    solve();
    return 0;
}