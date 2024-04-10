#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    string S;
    cin >> S;

    int N = S.length();

    int s = 0;
    for (int i = 0; i < N;) {
        int j;
        for (j = i; j < N && j < i + 5 && S[j] == S[i]; ++j);
        ++s;
        i = j;
    }

    cout << s << '\n';
}