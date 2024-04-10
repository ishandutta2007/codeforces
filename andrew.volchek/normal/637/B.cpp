#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200200;

int n;
map<string, int> m;
string res[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = n; i >= 1; i--) {
        string s;
        cin >> s;
        m[s] = i;
    }

    for (auto it : m) {
        res[it.second] = it.first;
    }

    for (int i = 1; i <= n; i++) {
        if (res[i].size() > 0) {
            cout << res[i] << "\n";
        }
    }

    return 0;
}