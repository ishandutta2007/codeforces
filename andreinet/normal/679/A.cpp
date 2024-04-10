#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    srand(time(0));
    int cnt = 0, first = -1;
    for (int i = 0; i < 19; ++i) {
        cout << primes[i] << endl;
        string s;
        cin >> s;
        if (s == "yes") {
            cnt++;
            first = primes[i];
        }
    }
    if (cnt >= 2) {
        cout << "composite" << endl;
    } else {
        if (first != -1 && first * first <= 100) {
            cout << first * first << endl;
            string s;
            cin >> s;
            cout << (s == "yes" ? "composite": "prime") << endl;
        } else {
            cout << "prime" << endl;
        }
    }
}