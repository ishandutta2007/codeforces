#include <bits/stdc++.h>

using namespace std;

string up (string s) {
    string r = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') r += '#';
        if (s[i] == '2') r += '#';
        if (s[i] == '3') r += '#';
        if (s[i] == '4') r += '1';
        if (s[i] == '5') r += '2';
        if (s[i] == '6') r += '3';
        if (s[i] == '7') r += '4';
        if (s[i] == '8') r += '5';
        if (s[i] == '9') r += '6';
        if (s[i] == '0') r += '8';
    }
    return r;
}

string down (string s) {
    string r = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') r += '4';
        if (s[i] == '2') r += '5';
        if (s[i] == '3') r += '6';
        if (s[i] == '4') r += '7';
        if (s[i] == '5') r += '8';
        if (s[i] == '6') r += '9';
        if (s[i] == '7') r += '#';
        if (s[i] == '8') r += '0';
        if (s[i] == '9') r += '#';
        if (s[i] == '0') r += '#';
    }
    return r;
}

string lft (string s) {
    string r = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') r += '#';
        if (s[i] == '2') r += '1';
        if (s[i] == '3') r += '2';
        if (s[i] == '4') r += '#';
        if (s[i] == '5') r += '4';
        if (s[i] == '6') r += '5';
        if (s[i] == '7') r += '#';
        if (s[i] == '8') r += '7';
        if (s[i] == '9') r += '8';
        if (s[i] == '0') r += '#';
    }
    return r;
}

string ryt (string s) {
    string r = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') r += '2';
        if (s[i] == '2') r += '3';
        if (s[i] == '3') r += '#';
        if (s[i] == '4') r += '5';
        if (s[i] == '5') r += '6';
        if (s[i] == '6') r += '#';
        if (s[i] == '7') r += '8';
        if (s[i] == '8') r += '9';
        if (s[i] == '9') r += '#';
        if (s[i] == '0') r += '#';
    }
    return r;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int n; string s;
    cin >> n;
    cin >> s;
    string u = up(s), d = down(s), l = lft(s), r = ryt(s);

    bool f1, f2, f3, f4;
    f1 = f2 = f3 = f4 = 1;

    for (int i = 0; i < n; ++i) {
        if (u[i] == '#') f1 = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (d[i] == '#') f2 = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (l[i] == '#') f3 = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (r[i] == '#') f4 = 0;
    }

    if (f1 or f2 or f3 or f4) printf("NO\n");
    else printf("YES\n");
    return 0;
}