#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int code[256];

int convert(const string &S, int base) {
    int ret = 0;
    for (int c: S) {
        ret = base * ret + code[c];
        if (ret >= 60) return 60;
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    string S1, S2;
    for (int i = 0, j = 0; i < int(S.length()); ++i) {
        if (S[i] == ':') {
            j = 1;
            continue;
        }
        (j == 0 ? S1: S2).push_back(S[i]);
    }

    for (int i = '0'; i <= '9'; ++i)
        code[i] = i - '0';
    for (int i = 'A'; i <= 'Z'; ++i)
        code[i] = i - 'A' + 10;

    int minbase = 2;
    for (char c: S) {
        if (c != ':')
            minbase = max(minbase, code[c] + 1);
    }

    vector<int> bases;
    for (int i = minbase; i <= 201; ++i) {
        int a = convert(S1, i), b = convert(S2, i);
        if (a < 24 && b < 60)
            bases.push_back(i);
    }

    if (int(bases.size()) > 100) cout << "-1\n";
    else {
        for (int p: bases)
            cout << p << ' ';
        if (int(bases.size()) == 0) cout << 0;
        cout << endl;
    }
}