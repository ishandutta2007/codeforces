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
        set<char> work;
        char prev = '%';
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != prev) {
                if (len % 2) work.insert(prev);
                prev = s[i];
                len = 1;
            } else len++;
        }
        if (len % 2) work.insert(prev);

        for (char c : work) {
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}