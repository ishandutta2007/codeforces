#include <cstdio>
using namespace std;

const int prime[] = {2, 3, 5, 7};

int N;
char s[20];
int cnt[5];

void load() {
    scanf("%d%s", &N, s);    
}

void add(int digit, int val) {
    for (int i = 1; i <= digit; i++) 
        for (int j = 0; j < 4; j++) 
            for (int x = i; !(x % prime[j]); x /= prime[j])
                cnt[j] += val;
}

void solve() {
    for (int i = 0; i < N; i++) 
        add(s[i] - '0', 1);
    for (int i = 3; i >= 0; i--) 
        while (cnt[i]) {
            add(prime[i], -1);
            printf("%d", prime[i]);
        }
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}