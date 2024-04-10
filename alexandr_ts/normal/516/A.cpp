#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int INF = 1e9;
const int EPS = 1e-9;

int q[1000];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    string s;
    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] - '0' <= 1)
            continue;
        if (s[i] == '2' || s[i] == '5' || s[i] == '7' || s[i] == '3')
            q[s[i]]++;
        if (s[i] == '4')
            q['2'] += 2, q['3']++;
        if (s[i] == '8')
            q['2'] += 3, q['7']++;
        if (s[i] == '9')
            q['3'] += 2, q['2']++, q['7']++;
        if (s[i] == '6')
            q['5']++, q['3']++;
    }
    for (int i = 1000; i >= 0; i--)
        for (int j = 0; j < q[i]; j++)
            cout << (char)i;
}