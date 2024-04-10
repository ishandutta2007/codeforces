#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int N = 1e6 + 10;

int a[N];
int ans1[N];
int ans2[N];
int beg[N];

vector <int> l;


int main() {
    //freopen("a.in", "r", stdin);
    int h;
    cin >> h;
    int n = 0;
    for (int i = 0; i <= h; i++) {
        scanf("%d", &a[i]);
        beg[i] = (int)l.size();
        for (int j = 0; j < a[i]; j++)
            l.pb(i);
        n += a[i];
    }
    int i1 = -1;
    for (int i = 0; i < h; i++)
        if (a[i] > 1 && a[i + 1] > 1) {
            i1 = i;
            break;
        }
    if (i1 == -1) {
        cout << "perfect";
        return 0;
    }

    //for (int i = 0; i < 5; i++) cout << beg[i] << " ";cout << endl;

    cout << "ambiguous\n";
    //dfs(0, i1, h, -1);
    ans1[0] = ans2[0] = -1;
    for (int i = 1; i < n; i++)
        ans1[i] = ans2[i] = beg[l[i] - 1];
    for (int i = 0; i < n; i++)
        printf("%d ", ans1[i] + 1);

    for (int i = 1; i < n; i++)
        if (l[i] == i1 + 1 && l[i] != l[i - 1]) {
            ans2[i]++;
            break;
        }

    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", ans2[i] + 1);
}