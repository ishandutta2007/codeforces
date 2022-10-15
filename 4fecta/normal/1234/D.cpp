#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int bit[26][100005];
string s;
int q, c, l, r;
char ch;

int query(int c, int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        sum += bit[c][i];
    }
    return sum;
}

void update(int c, int x, int val) {
    for (int i = x; i < 100005; i += i & -i) bit[c][i] += val;
}

int main() {
    boost();

    cin >> s >> q;
    for (int i = 0; i < s.length(); i++) {
        update(s[i] - 'a', i + 1, 1);
    }
    for (; q > 0; q--) {
        cin >> c;
        if (c == 1) {
            cin >> l >> ch;
            update(s[l - 1] - 'a', l, -1);
            s[l - 1] = ch;
            update(ch - 'a', l, 1);
        } else {
            cin >> l >> r;
            int sum = 0;
            for (int i = 0; i < 26; i++) {
                bool has = query(i, r) - query(i, l - 1);
                sum += has;
            }
            printf("%d\n", sum);
        }
    }

    return 0;
}