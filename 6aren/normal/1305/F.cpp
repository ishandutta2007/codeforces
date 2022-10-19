#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> process;
    set<int> prime;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 30; i++) {
        random_shuffle(all(a));
        process.push_back(a[0]);
        process.push_back(a[0] + 1);
        process.push_back(a[0] - 1);        
    }
    for (int e : process) {
        for (int i = 2; i * i <= e; i++) {
            if (e % i == 0) {
                prime.insert(i);
                while (e % i == 0) e /= i;
            }
        }
        if (e > 1) prime.insert(e);
    }
    int ans = 1e9;
    for (int p : prime) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            int foo = a[i] % p;
            if (a[i] == foo) {
                temp += p - foo;
            } else temp += min(foo, p - foo);
        }
        ans = min(ans, temp);
    }
    cout << ans;
    return 0;
}