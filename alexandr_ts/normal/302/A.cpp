#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 1;
const ld EPS = 1e-8;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    int l, r, cnt1 = 0, cnt2 = 0;
    fr(i, n)
        if (a[i] == 1) cnt1++;
        else cnt2++;
    fr(i,m) {
        cin >> l >> r;
        int qua = (r - l + 1);
        if (qua % 2 == 0 && cnt1 >= qua / 2 && cnt2 >= qua / 2)
            cout << 1 << endl;
        else cout << 0 << endl;
    }

}