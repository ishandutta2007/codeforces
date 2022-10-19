#include <cstdio>
using namespace std;

const int MAXN = 100005;

int N;
char s[2 * MAXN];
int cnt[30];

void load() {
    scanf("%d%s", &N, s);
}

int solve() {
    int sol = 0;
    for (int i = 0; i < N - 1; i++) {
        cnt[s[2 * i] - 'a']++;
        if (cnt[s[2 * i + 1] - 'A']) 
            cnt[s[2 * i + 1] - 'A']--;
        else sol++;
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}