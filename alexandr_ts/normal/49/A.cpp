#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 1e5;

bool used[N];

int main() {
    string s;
    getline(cin, s);
    string st;
    fr(i, s.size())
        if (isalnum(s[i]))
            st += tolower(s[i]);
    char c = st[(int)st.size() - 1];
    if (c == 'o' || c == 'a' || c == 'i' || c == 'e' || c == 'y' || c == 'u')
        cout << "YES";
    else
        cout << "NO";
}