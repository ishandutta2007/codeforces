#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

mt19937 gen(time(0));

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <char> my = {'a', 'e', 'o', 'i', 'u'};
    for (int i = 1; i < n; i++) {
        if (i >= 5 && n % i == 0 && (n / i) >= 5) {
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < n / i; k++) {
                    cout << my[(k + j) % 5];
                }
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
}