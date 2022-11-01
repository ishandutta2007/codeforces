#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const ll INF = 2e12 + 1;
const int ST = 110;
const ld EPS = 1e-12;
const ld PI = acos(-1);

struct tmp {
    int x, pos;
};

ll a[N];
tmp b[N];

queue <int> q;

bool cmp(tmp a, tmp b) {
    return a.x < b.x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    frab(i, 1, n + 1)
        b[i].pos = i, b[i].x = 0;

    fr(i, n) {
        cin >> a[i];
        if (!b[a[i]].x && a[i] <= n)
            b[a[i]].x = i + 1;
        else
            q.push(i + 1);
    }
    frab(i, 1, 1 + n)
        if (!b[i].x) {
            b[i].x = q.front();
            q.pop();
        }
    sort(b + 1, b + n + 1, cmp);
    frab(i, 1, n + 1)
        cout << b[i].pos << " ";

}