#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

string win = "Ashishgup\n";
string lose = "FastestFinger\n";

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest; 
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        if (n == 1) cout << lose;
        else if (n == 2) cout << win;
        else {
            int cnt = 0;
            while (n % 2 == 0) n /= 2, cnt++;
            if (n == 1 || (prime(n) && cnt == 1)) cout << lose;
            else cout << win;
        }
    }
    return 0;
}