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

int a[N];

int main() {
        //freopen("input.txt", "r", stdin);
    ld st = clock();
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n;
    int ans = INF;
    int qua = 0, pos;
    cin >> n;
    fr(i, n) {
        cin >> a[i];
        if (a[i] < ans)
            ans = a[i], pos = i, qua = 1;
        else
            if (a[i] == ans)
                qua++;
    }
    if (qua == 1)
        cout << pos + 1;
    else
        cout << "Still Rozdil";

}