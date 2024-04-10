#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 1e3;

int a[N][N];

int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int n, l, r, k;
    cin >> n;
    fr(i, n) {
        cin >> l >> r >> k;
        l--, r--;
        //if (l == r) continue;
        k %= (r - l + 1);
        k = (r - l + 1) - k;
        rotate(s.begin() + l, s.begin() + k + l, s.begin() + r + 1);
    }
    cout << s;
}