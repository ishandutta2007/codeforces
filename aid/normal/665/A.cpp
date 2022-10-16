#include <iostream>

using namespace std;

const int H = 60;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, ta, b, tb, sh, sm;
    char c;
    cin >> a >> ta >> b >> tb >> sh >> c >> sm;
    int s = sh * H + sm, sl = s, sr = s + ta, t = 5 * H, ans = 0;
    while(t <= 23 * H + 59) {
        int tl = t, tr = t + tb;
        if(!(tr <= sl) && !(tl >= sr))
            ans++;
        t += b;
    }
    cout << ans << '\n';
    return 0;
}