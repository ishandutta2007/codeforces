#include <iostream>

using namespace std;

const int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int get(int x) {
    int res = 0;
    while(x) {
        res += cnt[x % 10];
        x /= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a; i <= b; i++)
        ans += get(i);
    cout << ans << '\n';
    return 0;
}