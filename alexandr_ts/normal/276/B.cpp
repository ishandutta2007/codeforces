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
const ll INF = 2e9 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    fr(i, s.size())
        a[s[i]]++;
    fr(i, N)
        a[i] %= 2;
    int sum = accumulate(a, a + N, 0);
    //cout << sum << endl;
    if (sum <= 1) {
        cout << "First";
        return 0;
    }
    if (sum % 2 == 0) {
        cout << "Second";
        return 0;
    }
    cout << "First";
}