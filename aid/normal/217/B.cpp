#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

pair<int, int> gcd0(int a, int b) {
    if(b == 1)
        return make_pair(a, max(0, a - 2));
    pair<int, int> p = gcd0(b, a % b);
    p.first += a / b;
    p.second += max(0, a / b - 1);
    return p;
}

bool getPath(int a, int b) {
    if(b == 1) {
        cout << 'T';
        for(int i = 0; i < a - 1; i++)
            cout << 'B';
        return true;
    }
    bool t = getPath(b, a % b);
    for(int i = 0; i < a / b; i++)
        cout << (t? 'T' : 'B');
    return !t;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, r;
    cin >> n >> r;
    int ans = -1, pos = -1;
    for(int i = 1; i <= r; i++)
        if(gcd(i, r) == 1) {
            pair<int, int> p = gcd0(i, r);
            if(p.first == n && (ans == -1 || ans > p.second)) {
                ans = p.second;
                pos = i;
            }
        }
    if(ans == -1)
        cout << "IMPOSSIBLE\n";
    else {
        cout << ans << '\n';
        getPath(pos, r);
        cout << '\n';
    }
    return 0;
}