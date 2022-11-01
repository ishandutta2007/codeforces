#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

int main() {
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    for (int i = (int)s.size() - 1; i >= 0; i--)
        if (s[i] != 'z') {
            s[i]++;
            break;
        }
        else
            s[i] = 'a';
    if (s < t)
        cout << s;
    else
        cout << "No such string";
}