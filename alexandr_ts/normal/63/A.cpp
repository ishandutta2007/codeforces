#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e2 + 10;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

string s[N], t[N];
bool used[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n;
    cin >> n;
    fr(i, n)
        cin >> s[i] >> t[i];
    fr(i, n)
        if (t[i] == "rat")
            cout << s[i] << endl;
    fr(i, n)
        if (t[i] == "child" || t[i] == "woman")
            cout << s[i] << endl;
    fr(i, n)
        if (t[i] == "man")
            cout << s[i] << endl;
    fr(i, n)
        if (t[i] == "captain")
            cout << s[i] << endl;
}