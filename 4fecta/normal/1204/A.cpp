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

    string s;
    cin >> s;
    if (s == "0") {printf("0\n"); return 0;}
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') cnt++;
    }
    int ans = (s.length() + 1) / 2;
    if (s.length() % 2 && cnt == 1) ans--;
    printf("%d\n", ans);
    return 0;
}