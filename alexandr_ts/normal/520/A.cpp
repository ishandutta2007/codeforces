#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int ALPH = 26;

bool used[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        s[i] = tolower(s[i]);
    for (int i = 0; i < n; i++) {
        if (!used[s[i]]) m++;
        used[s[i]] = true;
    }
    if (m == ALPH)
        cout << "YES";
    else
        cout << "NO";

}