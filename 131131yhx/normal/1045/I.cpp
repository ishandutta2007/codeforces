#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long
#define MIT map <int, int>::iterator

using namespace std;

int A[100010], n;

char ch[1000010];

map <int, int> hsh;

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", ch + 1);
        int t = strlen(ch + 1);
        for(int j = 1; j <= t; j++) A[i] ^= 1 << (ch[j] - 'a');
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += hsh[A[i]] * 2, hsh[A[i]]++;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 26; j++)
            ans += hsh[A[i] ^ (1 << j)];
    printf("%lld\n", ans / 2);
    return 0;
}