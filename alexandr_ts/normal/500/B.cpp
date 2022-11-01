#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < (ll)n; i++)
#define frab(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 10;
const ll INF = 2e9;
const ll ALPH = 300;


int n;
int a[N];
int used[N];
string s[N];

void dfs(int v, int col) {
    used[v] = col;
    fr(i, n)
        if (i != v && !used[i] && s[i][v] == '1')
            dfs(i, col);
}

int main() {
        //freopen("input.txt", "r", stdin);
    ld st = clock();
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i,n)
        cin >> s[i];
    int cur = 1;
    fr(i, n)
        if (!used[i])
            dfs(i, cur++);
    fr(i, n)
        fr(j, n)
            if (used[i] == used[j])
                s[i][j] = '1';

    while (1) {
        if (clock() - st > 190)
            break;
        fr(i, n)
            frab(j, i, n)
                if (s[i][j] == '1' && a[i] > a[j])
                    swap(a[i], a[j]);
    }
    fr(i, n)
        cout << a[i] << " ";
}