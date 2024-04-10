#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define ll long long
#define endl '\n'
#define fc first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, n) for(int i = 0; i < (int) (n); i++)

const int MOD = (int) 1e9 + 7;

set <int> nums;
int lim = 0;
string a, b;
int ans = 0;

string kek;

void rec(int cur, bool s) {
    if (cur == (int) a.size()) {
        s = 0;
    }
    if (cur < (int) a.size()) {
        if (s) {
            for (int i = 0; i < 7; i++) {
                if (!nums.count(i)) {
                    nums.insert(i);
                    kek += (i + '0');
                    rec(cur + 1, s);
                    kek.pop_back();
                    nums.erase(i);        
                }
            }
        } else {
            if (!nums.count(a[cur] - '0')) {
                int i = a[cur] - '0';
                nums.insert(i);
                kek += (i + '0');
                rec(cur + 1, 0);
                kek.pop_back();
                nums.erase(i);
            }
            for (int i = 0; i < (a[cur] - '0'); i++) {
                if (!nums.count(i)) {
                    nums.insert(i);
                    kek += (i + '0');
                    rec(cur + 1, 1);
                    kek.pop_back();
                    nums.erase(i);
                }
            }
        }
    } else if (cur < (int) b.size()) {
        if (s) {
            for (int i = 0; i < 7; i++) {
                if (!nums.count(i)) {
                    nums.insert(i);
                    kek += (i + '0');
                    rec(cur + 1, s);
                    kek.pop_back();
                    nums.erase(i);        
                }
            }
        } else {
            if (!nums.count(b[cur] - '0')) {
                int i = b[cur] - '0';
                nums.insert(i);
                kek += (i + '0');
                rec(cur + 1, 0);
                kek.pop_back();
                nums.erase(i);
            }
            for (int i = 0; i < (b[cur] - '0'); i++) {
                if (!nums.count(i)) {
                    nums.insert(i);
                    kek += (i + '0');
                    rec(cur + 1, 1);
                    kek.pop_back();
                    nums.erase(i);
                }
            }
        }
    } else {
        ans++;
        //cout << kek << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif   
    int n, m;
    cin >> n >> m;
    n--, m--;
    if (n == 0) {
        a = "0";
    }
    while (n > 0) {
        a += (n % 7 + '0');
        n /= 7;
    }
    if (m == 0) {
        b = "0";
    }
    while (m > 0) {
        b += (m % 7 + '0');
        m /= 7;
    }
    reverse(all(a));
    reverse(all(b));
    b = a + b;
    rec(0, 0);
    cout << ans << endl;
}