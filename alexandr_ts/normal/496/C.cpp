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

string s[N];
int cl[N], tmpcl[N];

int main() {
        //freopen("input.txt", "r", stdin);
    ld st = clock();
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n, m, curCl = 1;
    cin >> n >> m;
    fr(i, n)
        cin >> s[i];
    int ans = 0;
    fr(i, m) {
        bool er = false;
        fr(j, n - 1)
            if (cl[j] == cl[j + 1] && s[j][i] > s[j + 1][i]) {
                er = true;
                ans++;
                break;
            }
        if (er) continue;
        fr(j, n - 1)
            if (cl[j] == cl[j + 1])
                if(s[j][i] < s[j + 1][i])
                    tmpcl[j + 1] = curCl++;
                else
                    tmpcl[j + 1] = tmpcl[j];
            else
                tmpcl[j + 1] = cl[j + 1];
        fr(j, n)
            cl[j] = tmpcl[j];
    }
    cout << ans;

}