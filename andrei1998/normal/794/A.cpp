#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    int N;
    cin >> N;
    while (N --) {
        int val;
        cin >> val;
        if (b < val && val < c)
            ++ ans;
    }

    cout << ans << '\n';
    return 0;
}