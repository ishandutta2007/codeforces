#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define read(a) scanf("%d", &a)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

int a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int n, q;
    read(n);
    fr(i, n)  {
        read(q);
        a[q - 1]++;
    }
    fr(i, s.size() / 2)
        b[i] = a[i] + (i ? b[i - 1] : 0);
    fr(i, s.size() / 2)
        if (b[i] % 2)
            swap(s[i], s[(int)s.size() - i - 1]);
    cout << s;
}