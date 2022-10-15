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

        int n;
        string s;
        cin >> n >> s;
        int first = -1, last;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (first == -1) {
                    first = i;
                    
                }
                last = i;
            }
        }
        if (first == -1) printf("%d\n", n);
        else printf("%d\n", max((n - first) * 2, (last + 1) * 2));
    }

    return 0;
}