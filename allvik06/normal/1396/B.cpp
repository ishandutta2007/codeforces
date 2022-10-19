#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve1(int n, vector <int>& a) {
    int sum = 0, maxx = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        maxx = max(maxx, a[i]);
    }
    if ((sum - maxx) < maxx) {
        cout << "T\n";
        return;
    }
    if (sum % 2 == 0) cout << "HL\n";
    else cout << "T\n";
}

int solve2() {

}

signed main (){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            solve1(n, a);
        }
    }
    else {
        int t;
        cin >> t;
        while (t--) {
            int n = rand() % 1000000;
            vector <int> a(n);
            for (int i = 0; i < n; ++i) {
                a[i] = rand();
            }
            solve1(n, a);
        }
    }
}