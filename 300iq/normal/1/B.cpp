#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

string to1(string a) {
    int r = 0, c = 0;
    int i;
    for (i = 0; a[i] >= 'A' && a[i] <= 'Z'; i++) {
        r = r * 26 + (a[i] - 'A' + 1);
    }
    for (; i < (int) a.size(); i++) {
        c = c * 10 + (a[i] - '0');
    }
    swap(r, c);
    return "R" + to_string(r) + "C" + to_string(c);
}

string go(int x) {
    string t = "";
    while (x > 0) {
        int p = x % 26;
        if (p == 0) {
            p = 26;
            x--;
        }
        t += (p + 'A' - 1);
        x /= 26;
    }
    reverse(all(t));
    return t; 
}

string to2(string s) {
    int i;
    string p = "";
    for (i = 1; s[i] != 'C'; i++) {
        p += s[i];
    }
    i++;
    int t = 0;
    while (i < (int) s.size()) {
        t = t * 10 + (s[i] - '0');
        i++;
    }
    return go(t) + p;
}

bool t2(string s) {
    int i = 0;
    while (s[i] >= 'A' && s[i] <= 'Z') {
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9') {
        i++;
    }
    return (i == (int) s.size());
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!t2(s)) {
            cout << to2(s) << endl;
        } else {
            cout << to1(s) << endl;
        }
    }
}