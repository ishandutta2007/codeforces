#include <bits/stdc++.h>
#define mp make_pair
#define fc first;
#define sc second;

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    if (b > 0) {
        while (b--) {
            a++;
            a %= n;
        }
        cout << a + 1 << endl;
    } else {
        while (b++) {
            a--;
            if (a < 0) {
                a += n;
            }
        }
        cout << a + 1 << endl;
    }
}