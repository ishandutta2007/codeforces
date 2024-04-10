#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
    int L, M; string S;
    cin >> L >> S;
    set <char> T;
    for (int i = 0; i < L; i++) T.insert(S[i]);
    M = T.size();
    if (L > 26) cout << -1 << endl;
    else cout << L - M << endl;
    return 0;
}