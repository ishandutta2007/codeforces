#include <bits/stdc++.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int main() {
    init_cin
    string s;
    cin >> s;
    int n;
    cin >> n;
    map<string, int> pts;
    map<string, int> add;
    add["posted"] = 15;
    add["commented"] = 10;
    add["likes"] = 5;
    for (int i = 0; i < n; i++) {
        string s1, cmd;
        cin >> s1 >> cmd;
        string s2, t;
        if (cmd == "likes") {
            cin >> s2 >> t;
        } else {
            cin >> t >> s2 >> t;
        }
        s2 = s2.substr(0, s2.size() - 2);
        if (s1 == s) {
            pts[s2] += add[cmd];
        } else if (s2 == s) {
            pts[s1] += add[cmd];
        } else {
            pts[s1] += 0;
            pts[s2] += 0;
        }
    }


    vector<pair<int, string> > ans;
    for (auto& i : pts) {
        ans.push_back({-i.second, i.first});
    }
    sort(ans.begin(), ans.end());
    for (auto& i : ans) {
        cout << i.second << "\n";
    }

    return 0;
}