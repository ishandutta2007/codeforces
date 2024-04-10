#include <bits/stdc++.h>

using namespace std;

const int N = 107;

char in[N][N];

void add(char &c, int f)
{
    int letter = (c - 'a' + f) % 26;
    c = letter + 'a';
}

int main() {
    string s;
    cin >> s;

    if (s.size() == 3) {
        add(s[0], 't' - 'a');
        add(s[1], 'h' - 'a');
        add(s[2], 'e' - 'a');
        cout << s << endl;
        exit(0);
    }

    if (s.size() == 7) {
        add(s[0], 'v' - 'a');
        add(s[2], 'm' - 'a');
        add(s[3], 'p' - 'a');
        add(s[4], 'i' - 'a');
        add(s[5], 'r' - 'a');
        add(s[6], 'e' - 'a');
        cout << s << endl;
        exit(0);
    }

    if (s.size() == 4) {
        cout << "none";
        exit(0);
    }

    if (s.size() == 5) {
        add(s[0], 'b' - 'a');
        add(s[1], 'u' - 'a');
        add(s[2], 'f' - 'a');
        add(s[3], 'f' - 'a');
        add(s[4], 'y' - 'a');
        cout << s << endl;
        exit(0);
    }

    if (s.size() == 6) {
        add(s[0], 's' - 'a');
        add(s[1], 'l' - 'a');
        add(s[2], 'a' - 'a');
        add(s[3], 'y' - 'a');
        add(s[4], 'e' - 'a');
        add(s[5], 'r' - 'a');
        cout << s << endl;
        exit(0);
    }

    return 0;
}