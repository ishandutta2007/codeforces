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



int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    int ca = 0;
    string s;
    cin >> s;
    fr(i, n)
        if (s[i] == 'A')
            ca++;
    if (ca > n - ca)
        cout << "Anton";
    else if (ca < n - ca)
        cout << "Danik";
    else
        cout << "Friendship";
}