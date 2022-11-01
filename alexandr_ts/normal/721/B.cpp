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
    fr(i, n)
        cin >> s[i];
    string pas;
    cin >> pas;
    //sort(s, s + n, cmp);
    int cs = 0, ce = 0;
    fr(i, n)
        if (s[i].size() < pas.size())
            cs++;
        else if (s[i].size() == pas.size())
            ce++;
    int mn = cs + 5 * (cs / k) + 1;
    int mx = cs + (ce - 1) + 5 * ((cs + ce - 1) / k) + 1;
    cout << mn << " " << mx;
}