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
const ld PI = acos(-1);
const int MOD = 1e9 + 7;

char a[N][N];
int dist[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct tmp {
    int x, y, dist;
} ar[N * N];

bool cmp(tmp a, tmp b) {
    return a.dist < b.dist;
}

int main() {
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    fr(i, s.size()) {
        int x = s[i] - '0';
        if (x >= 5) {
            cout << "-O";
            x -= 5;
        }
        else cout << "O-";
        if (x == 0) cout << "|-OOOO";
        if (x == 1) cout << "|O-OOO";
        if (x == 2) cout << "|OO-OO";
        if (x == 3) cout << "|OOO-O";
        if (x == 4) cout << "|OOOO-";
        cout << endl;
    }


}