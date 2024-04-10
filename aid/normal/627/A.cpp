#include <iostream>

using namespace std;

const long long K = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long s, x;
    cin >> s >> x;
    int xx = (x & ((1 << K) - 1)), ss = (s & ((1 << K) - 1));
    int cnt0 = 0, cnt1 = 0;
    for(int a = 0; a < (1 << K); a++) {
        int b = (xx ^ a);
        if(ss == a + b)
            cnt0++;
        else if(ss == a + b - (1 << K))
            cnt1++;
    }
    xx = (x >> K);
    ss = (s >> K);
    long long ans = 0;
    for(int a = 0; a < (1 << K); a++) {
        int b = (xx ^ a);
        if(ss == a + b)
            ans += cnt0;
        else if(ss == a + b + 1)
            ans += cnt1;
    }
    if(s == x)
        ans -= 2;
    cout << ans << '\n';
    return 0;
}