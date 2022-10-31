#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

int n;
string s[N];

int hamming(string a, string b) {
    int res = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) ++res;
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    int res = 6;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            res = min(res, (hamming(s[i], s[j]) - 1) / 2);
        }
    }

    printf("%d\n", res);

    return 0;
}