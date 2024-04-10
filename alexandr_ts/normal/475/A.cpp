#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e3 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

string s[10];

int main() {
    s[0] = "+------------------------+";
    s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    s[3] = "|#.......................|";
    s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    s[5] = "+------------------------+";
    int n;
    cin >> n;
    fr(i, n) {
        bool fnd = false;
            fr(k, 30)        fr(j, 7)

                if (s[j][k] == '#' && !fnd) {
                    s[j][k] = 'O';
                    fnd = true;
                    break;
                }
    }
    fr(i, 6)
    cout << s[i] << endl;
}