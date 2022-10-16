#include <iostream>

using namespace std;

const int N = 505, INF = 1000 * 1000 * 1000 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    int hpy, atky, defy, hpm, atkm, defm, h, a, d;
    cin >> hpy >> atky >> defy >> hpm >> atkm >> defm >> h >> a >> d;
    int ans = INF;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            int cur = i * a + j * d;
            atky += i;
            defy += j;
            int dely = max(0, atkm - defy), delm = max(0, atky - defm);
            if(delm == 0) {
                atky -= i;
                defy -= j;
                continue;
            }
            int k = (hpm + delm - 1) / delm;
            if(hpy > k * dely)
                ans = min(ans, cur);
            else
                ans = min(ans, cur + (k * dely + 1 - hpy) * h);
            atky -= i;
            defy -= j;
        }
    cout << ans << '\n';
    return 0;
}