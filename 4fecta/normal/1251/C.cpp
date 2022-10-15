#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int main() {
    boost();
    int q;
    cin >> q;
    for (; q > 0; q--) {
        string s;
        cin >> s;
        string ans;
        queue<char> ev;
        queue<char> od;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] - '0') % 2) od.push(s[i]);
            else ev.push(s[i]);
        }

        while (ev.size() || od.size()) {
            if (ev.empty()) {
                ans += od.front();
                od.pop();
                continue;
            }
            else if (od.empty()) {
                ans += ev.front();
                ev.pop();
                continue;
            }
            if (ev.front() < od.front()) {
                ans += ev.front();
                ev.pop();
            }
            else {
                ans += od.front();
                od.pop();
            }
        }
        printf("%s\n", ans.c_str());
    }

    return 0;
}