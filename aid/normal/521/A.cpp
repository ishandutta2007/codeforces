#include <iostream>
#include <string>

using namespace std;

const int SIGMA = 4, MOD = 1000 * 1000 * 1000 + 7;
int cnt[SIGMA];

int f(char c) {
    return (c == 'A'? 0 : (c == 'C'? 1 : (c == 'G'? 2 : 3)));
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cnt[f(s[i])]++;
    int maxCnt = 0;
    for(int i = 0; i < SIGMA; i++)
        maxCnt = max(maxCnt, cnt[i]);
    int k = 0;
    for(int i = 0; i < SIGMA; i++)
        if(cnt[i] == maxCnt)
            k++;
    int ans = 1;
    for(int i = 0; i < n; i++)
        ans = ((long long)ans * k) % MOD;
    cout << ans << '\n';
    return 0;
}