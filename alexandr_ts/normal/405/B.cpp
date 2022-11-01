#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, n) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e2 + 1;

char a[N][N];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    int pos = 0, posl = -1, posr = -1;
    fr(i, n) {
        if (s[i] == 'L') {
            posl = i;
            break;
        }
        else if (s[i] == 'R') {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == 'R') {
            posr = i;
            break;
        }
        else if (s[i] == 'L')
            break;
    bool fnd = false;
    fr(i, n) {
        if (s[i] == 'R')
            pos = i, fnd = true;
        if (s[i] == 'L' && fnd)
            ans += (i - pos + 1) - (i - pos + 1) % 2;
    }
    if (posl != -1)
        ans += (posl + 1);
    if (posr != -1)
        ans += (n - posr);
    cout << n - ans;

}