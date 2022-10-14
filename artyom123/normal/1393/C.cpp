#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

mt19937 gen(time(0));

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<int> cnt(n + 1);
        for (auto &c : a) cnt[c]++;
        int left = 0, right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            bool ok = true;
            int blocks = n / (mid + 1);
            int cnt_more = 0;
            for (auto &c : cnt) {
                if (c > blocks) cnt_more++;
                if (c > blocks + 1) ok = false;
            }
            if (!ok || cnt_more > n % (mid + 1)) right = mid;
            else left = mid;
        }
        cout << left << "\n";
    }
    return 0;
}