#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

string sort(const string &s) {
    int n = sz(s);
    if (n % 2) return s;
    string a = sort(s.substr(0, n / 2));
    string b = sort(s.substr(n / 2));
    if (a > b) swap(a, b);
    return a + b;
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    puts(sort(a) == sort(b) ? "YES" : "NO");
    return 0;
}