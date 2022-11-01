#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 53;
const int N = 1e6 + 10;

bool first[N], last[N];
bool used1[N], used2[N];

char s[N];

int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    scanf("%s", &s);
    fr(i, n) {
        if (!used1[s[i]])
            first[i] = true;
        used1[s[i]] = true;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!used2[s[i]])
            last[i] = true;
        used2[s[i]] = true;
    }

    int cur = 0;
    fr(i, n) {
        if (first[i])
            cur++;
        if (cur > k) {
            cout << "YES";
            return 0;
        }
        if (last[i])
            cur--;
    }
    cout << "NO";
}