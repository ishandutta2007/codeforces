#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, q;

bool turn(char c) {
    return (c - '0' > 2);
}

int main() {
    boost();
    cin >> q;
    for (; q > 0; q--) {
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool flag = 0;
        bool can = 1;
        for (int i = 0; i < n; i++) {
            if (!flag) {
                if (turn(a[i])) {
                    if (!turn(b[i])) {
                        can = 0;
                        break;
                    } else {
                        flag = 1;
                    }
                }
            } else {
                if (turn(b[i])) {
                    if (!turn(a[i])) {
                        can = 0;
                        break;
                    } else {
                        flag = 0;
                    }
                }
            }
        }
        if (can && flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}