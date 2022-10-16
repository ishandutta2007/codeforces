#include <bits/stdc++.h>

using namespace std;

bool vowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' ||
           ch == 'e' ||
           ch == 'i' ||
           ch == 'o' ||
           ch == 'u';
}

int cnt[] = {5, 7, 5};

int main()
{
    for (int i = 0; i < 3; ++ i) {
        string str;
        getline(cin, str);

        int ans = 0;
        for (auto it: str)
            if (vowel(it))
                ++ ans;

        if (ans != cnt[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}