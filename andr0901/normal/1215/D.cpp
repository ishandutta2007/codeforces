#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
 
const string bad = "Monocarp", good = "Bicarp";
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int sum_dif = 0, question_dif = 0;
    forn (i, 0, n / 2) {
        char c;
        cin >> c;
        if (c == '?') 
            question_dif++;
        else
            sum_dif += c - '0';
    }
    forn (i, n / 2, n) {
        char c;
        cin >> c;
        if (c == '?') 
            question_dif--;
        else
            sum_dif -= c - '0';
    }
    if (-question_dif / 2 * 9 == sum_dif)
        cout << good;
    else
        cout << bad;
    return 0;
}