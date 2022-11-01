#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 10000*10000;
const ll INF = 2e9 + 10;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    int n = s.size();
    bool er = false;
    fr(i, n) {
        if (s[i] == '5' && s[n - 1 - i] != '9') er = true;
        if (s[i] == '9' && s[n - 1 - i] != '5') er = true;
        if (s[i] == '8' && s[n - 1 - i] != '0') er = true;
        if (s[i] == '0' && s[n - 1 - i] != '8') er = true;
        if (s[i] == '4' && s[n - 1 - i] != '6') er = true;
        if (s[i] == '6' && s[n - 1 - i] != '4') er = true;
        if (s[i] == '3' && s[n - 1 - i] != '3') er = true;
        if (s[i] == '7' && s[n - 1 - i] != '7') er = true;
        if (s[i] == '1' || s[i] == '2') er = true;
    }
    if (er)
        cout << "No";
    else
        cout << "Yes";
}