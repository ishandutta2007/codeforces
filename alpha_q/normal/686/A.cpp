#include <bits/stdc++.h>

using namespace std;

int n, no = 0;
long long d, x;
char c;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> x; while (n--) {
        cin >> c >> d;
        if (c == '+') x += d;
        else {
            if (x >= d) x -= d;
            else ++no;
        }
    }

    cout << x << " " << no << endl;

    cout.flush();
    return 0;
}