#include <iostream>
#include <iomanip>

using namespace std;

const int M = 60, H = 24;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h, m, a;
    char c;
    cin >> h >> c >> m >> a;
    int t = h * M + m;
    t = (t + a) % (H * M);
    cout << setfill('0') << setw(2) << t / M << ":"
         << setfill('0') << setw(2) << t % M << '\n';
    return 0;
}