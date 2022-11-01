#include <algorithm>
#include <iostream>
#include <cassert>
#include <bitset>
#include <random>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define FOR(i, a, b) for (int i(a), b_(b); i < b_; ++i)
#define REP(i, n) FOR (i, 0, n)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int weekday(string s) {
     string w[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
     REP (i, 7) if (w[i] == s) return i;
     return -1;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int x = weekday(a);
    int y = weekday(b);
    int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    REP (i, 11) {
        if ((x + m[i]) % 7 == y) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}