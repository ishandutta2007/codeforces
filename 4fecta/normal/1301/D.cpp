#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, m, k;
string ans;
vector<int> ans1;
vector<string> ans2;

void go(const string& c) {
    int times = (n - 1) / 4;
    int rem = (n - 1) % 4;
    if (times) ans1.push_back(times);
    if (times) ans2.push_back(c + c + c + c);
    if (rem) {
        ans = "";
        ans1.push_back(1);
        for (int i = 0; i < rem; i++) ans += c;
        ans2.push_back(ans);
    }
}

void right() {
    ans1.push_back(1);
    ans2.push_back("R");
}

void weird() {
    if (n < 2) return;
    ans1.push_back(n - 1);
    ans2.push_back("DLR");
}

int main() {
    boost();

    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m) return 0 * printf("NO\n");
    go("D"), go("U");
    for (int col = 2; col <= m; col++) {
        right();
        weird();
        go("U");
    }
    n = m;
    go("L");
    int cnt = 0;
    //for (int j = 0; j < ans1.size(); j++) printf("%d %s\n", ans1[j], ans2[j].c_str());
    for (int i = 0; i < ans1.size(); i++) {
        int t = ans1[i];
        ans = ans2[i];
        int l = ans.length();
        if (cnt + t * l < k) {cnt += t * l; continue;}
        else {
            int nt = (k - cnt) / l;
            int rem = (k - cnt) % l;
            //printf("%d %d %s\n", nt, rem, ans.c_str());
            if (nt) i++;
            if (rem) i++;
            printf("YES\n%d\n", i);
            if (nt) i--;
            if (rem) i--;
            for (int j = 0; j < i; j++) printf("%d %s\n", ans1[j], ans2[j].c_str());
            if (nt) printf("%d %s\n", nt, ans.c_str());
            if (rem) printf("1 %s\n", ans.substr(0, rem).c_str());
            return 0;
        }
    }
    printf("%d\n", cnt);

    return 0;
}