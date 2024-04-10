#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
string s;

int id = 0;
vector<int> d, ids[maxn];
int can(int len) {
    int lines = 1;
    int cur_len = 0;
    for(int i = 0; i <= id; i++) {
        if(lines > k) return false;
        if(d[i] + cur_len <= len) {
            cur_len += d[i];
            continue;
        }
        int was = 0;
        int max_len = -1;
        for(int lens: ids[i]) {
            if(cur_len + lens <= len && d[i] - lens <= len) {
                was = 1;
                max_len = lens;
            }
        }
        if(was) {
            cur_len = d[i] - max_len;
            lines++;
            continue;
        }

        cur_len = 0;
        lines++;
        if(d[i] + cur_len <= len) {
            cur_len += d[i];
            continue;
        }
        was = 0;
        max_len = -1;
        for(int lens: ids[i]) {
            if(cur_len + lens <= len && d[i] - lens <= len) {
                was = 1;
                max_len = lens;
            }
        }
        if(was) {
            cur_len = d[i] - max_len;
            lines++;
            continue;
        }
        return false;
    }

    return lines <= k;
}
void solve() {
    getline(cin, s);
    k = stoi(s);
    getline(cin, s);
    int l = 1, r = s.size();
    int res = -1;
    int len = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ' || s[i] == '-') {
            len++;
            d.emplace_back(len);
            ids[id].emplace_back(len);
            len = 0;
            id++;
        } else {
            len++;
        }
    }
    d.emplace_back(len);
    ids[id].emplace_back(len);
    if(d.size() == 1 || k == 1) {
        cout << s.size() << "\n";
        return;
    }

    while(l <= r) {
        int mid = (l + r)/2;
        if(can(mid)) {
            r = mid-1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << res << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}