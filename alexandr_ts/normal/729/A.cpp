#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 3;

int a[N];
bool b[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    fr(i, n) {
        if (i + 2 < n && s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
            ans += "***";
            i += 2;
            while (i + 2 < n && s[i + 1] == 'g' && s[i + 2] == 'o')
                i += 2;
        }
        else
            ans += s[i];
    }
    cout << ans;
}