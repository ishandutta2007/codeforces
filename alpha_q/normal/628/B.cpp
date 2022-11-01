#include <bits/stdc++.h>

using namespace std;

#define MAX 300005

char S[MAX]; long long i, j, L, Ret = 0;

int main() {
    scanf ("%s", S); L = strlen(S);

    for (i = 0; i < L; i++)
        if (S[i] == '0' or S[i] == '4' or S[i] == '8')
            ++Ret;

    for (i = 0; i < L - 1; i++) {
        j = 10 * (S[i] - '0') + (S[i + 1] - '0');
        if (j % 4 == 0) Ret += i + 1;
    }

    cout << Ret << endl;
    return 0;
}