#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 301;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

string s[N];
//bool cmp(string s, string t) {
//    return s.size() < t.size();
//}

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int p1 = s.find("G");
    int p2 = s.find("T");
    if (abs(p1 - p2) % k) {
        cout << "NO";
        return 0;
    }
    int t = abs(p1 - p2) / k;
    int step;
    if (p1 < p2) step = k;
    else step = -k;
    for (int i = 1; i < t; i++)
    if (s[p1 + step * i] != '.') {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}