#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 30;

int N;
int a[MAXN], b[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

string rev(string x) {
    reverse(x.begin(), x.end());
    return x;
}

void solve() {
    int g = 0;
    for (int i = 0; i < N; i++)
        g = __gcd(g, a[i]);
        
    for (int i = g; i; i--) {
        if (g % i) continue;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            b[j] = a[j] / i;
            cnt += b[j] % 2;
        }
        if (cnt > cnt % 2) continue;
        string sol = "", mid = "";
        for (int j = 0; j < N; j++) {
            if (b[j] % 2) mid += 'a' + j; 
            sol += string(b[j] / 2, 'a' + j);
        }
        sol += mid + rev(sol);
        int res = i;
        if (!(cnt % 2) && i < g) res *= 2;
        printf("%d\n", res);
        while (i--) printf("%s", sol.c_str());
        puts("");
        return;
    }
    
    puts("0");
    for (int i = 0; i < N; i++)
        printf("%s", string(a[i], 'a' + i).c_str());
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}