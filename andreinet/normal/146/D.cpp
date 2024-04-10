#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

bool good(const string &S, int a1, int a2, int a3, int a4) {
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    for (char c: S)
        (c == '4' ? s1: s2)++;
    for (int i = 0; i < int(S.length()) - 1; ++i) {
        if (S[i] == '4' && S[i + 1] == '7') ++s3;
        else if (S[i] == '7' && S[i + 1] == '4') ++s4;
    }
    return s1 == a1 && s2 == a2 && s3 == a3 && s4 == a4;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    string S;

    if (a3 != a4) {
        if (a3 > a4) {
            for (int i = 0; i < a1 - a4; ++i)
                S += '4';
            for (int i = 0; i < a4; ++i)
                S += "74";
            for (int i = 0; i < a2 - a4; ++i)
                S += '7';
        } else {
            S += '7';
            for (int i = 0; i < a1 - a4 + 1; ++i)
                S += '4';
            for (int i = 0; i < a4 - 2; ++i)
                S += "74";
            for (int i = 0; i < a2 - a4 + 1; ++i)
                S += '7';
            S += '4';
            cerr << S;
        }
    } else {
        string S1, S2;
        for (int i = 0; i < a1 - a3; ++i)
            S1 += '4';
        for (int i = 0; i < a3 - 1; ++i)
            S1 += "74";
        for (int i = 0; i < a2 - a3 + 1; ++i)
            S1 += '7';
        S1 += '4';

        S2 += '7';
        for (int i = 0; i < a1 - a3; ++i)
            S2 += '4';
        for (int i = 0; i < a3; ++i)
            S2 += "47";
        for (int i = 0; i < a2 - a3 - 1; ++i)
            S2 += '7';

        if (good(S1, a1, a2, a3, a4)) S = S1;
        else S = S2;
    }


    if (good(S, a1, a2, a3, a4))
        cout << S << '\n';
    else
        cout << "-1\n";
}