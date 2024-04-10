#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e2 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

char ar[N];

int main() {
    //freopen("birthday.in", "r", stdin);
    //freopen("birthday.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    fr(i, N)
        ar[i] = i;
    string s;
    cin >> s;
    char a, b;
    fr(i, m) {
        cin >> a >> b;
        int p1 = 0, p2 = 0;
        fr(j, N)
            if (ar[j] == a)
                p1 = j;
        fr(j, N)
            if (ar[j] == b)
                p2 = j;
        swap(ar[p1], ar[p2]);
    }
    fr(i, n)
        s[i] = ar[s[i]];
    cout << s;

}