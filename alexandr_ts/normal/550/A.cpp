#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e5 + 1;
const ll M = 2 * 1e3 + 1;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

int pr1[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    int lab = INF, rab = -1, lba = INF, rba = -1;
    frab(i, 1, s.size())
        if (s[i] == 'B' && s[i - 1] == 'A') {
            lab = min(lab, i - 1);
            rab = max(rab, i - 1);
        }
        else if (s[i] == 'A' && s[i - 1] == 'B') {
            lba = min(lba, i - 1);
            rba = max(rba, i - 1);
        }
    if (lab < rba - 1 || lba < rab - 1)
        cout << "YES";
    else
        cout << "NO";
 }