 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

int get_len(int x, int k) {
    int len = 0;
    while (x) {
        x /= k;
        len++;
    }
    return max(1, len);
}

vector<int> getx(int x, int k, int len) {
    vector<int> a;
    while (x) {
        a.pb(x % k);
        x /= k;
    }
    while ((int)a.size() < len) a.pb(0);
    return a;
}

void print(vector<int> a) {
    reverse(all(a));
    for (auto &c : a) cout << c;
    cout << endl << endl;
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        /*
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        */
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int len = get_len(n - 1, k);
        vector<int> cur(len, 0);
        for (int x = 0; x < n; x++) {
            //print(cur);
            vector<int> a = getx(x, k, len);
            if (x % 2 == 1) {
                for (auto &c : a) c *= -1;
            }
            vector<int> ask = a;
            for (int i = 0; i < len; i++) {
                ask[i] += cur[i];
                ask[i] += k;
                ask[i] %= k;
            }
            reverse(all(ask));
            int y = 0;
            for (auto &c : ask) {
                y *= k;
                y += c;
            }
            reverse(all(ask));
            cout << y << endl;
            int r;
            cin >> r;
            if (r == 1) break;
            for (auto &c : cur) c *= -1;
            for (int i = 0; i < len; i++) {
                cur[i] += ask[i];
                cur[i] %= k;
                cur[i] += k;
                cur[i] %= k;
            }
        }
    }
    return 0;
}