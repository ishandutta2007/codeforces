#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
    string str;
    cin >> str;

    int ans = 0;
    for (auto it: str) {
        if (isdigit(it) && (it - '0') % 2 == 1)
            ++ ans;
        if (isVowel(it))
            ++ ans;
    }

    cout << ans << '\n';
    return 0;
}