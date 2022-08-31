#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ios_base::sync_with_stdio(0);
    char c;
    int n;
    string t = "+";
    int a = 1, b = 0;
    while (cin >> c) {
        if (c == '=') {
            break;
        } else {
            a += (c == '+');
            b += (c == '-');
            if (c != '?') {
                t += c;
            }
        }
    }
    cin >> n;
    int s = a - b;
    vector <int> p(a, 1);
    vector <int> m(b, 1);
    for (int i = 0; i < a; i++) {
        while (p[i] + 1 <= n && abs(s + 1 - n) < abs(s - n)) {
            p[i]++;
            s++;
        }
    }
    for (int i = 0; i < b; i++) {
        while (m[i] + 1 <= n && abs((s - 1) - n) < abs(s - n)) {
            m[i]++;
            s--;
        }
    }
    if (s == n) {
        cout << "Possible" << endl;
        int l = 0, r = -1;
        cout << p[l];
        for (int i = 1; i < (int) t.size(); i++) {
            if (t[i] == '+') {
                l++;
                cout << " " << t[i] << " " << p[l];
            } else {
                r++;
                cout << " " << t[i] << " " << m[r];
            }
        }
        cout << " = " << n << endl;
    } else {
        cout << "Impossible" << endl;
    }
}