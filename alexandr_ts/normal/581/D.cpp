#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2 * 1e6;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

struct pt {
    int x, y, num;
    bool operator < (const pt a) const {
        return x < a.x || x == a.x && y < a.y;
    }
};

pt a[3];

void check(pt a, pt b, pt c) {
    if (a.x == b.x + c.x && a.y + b.y == a.x && b.y == c.y) {
        cout << a.x << endl;
        fr(i, a.y) {
            fr(j, a.x)
                cout << (char)('A' + a.num);
            cout << endl;
        }
        fr(i, b.y) {
            fr(j, b.x)
                cout << (char)('A' + b.num);
            fr(j, c.x)
                cout << (char)('A' + c.num);
            cout << endl;
        }
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    fr(i, 3) {
        cin >> a[i].x >> a[i].y;
        if (a[i].x < a[i].y)
            swap(a[i].x, a[i].y);
        a[i].num = i;
    }
    if (a[0].x == a[1].x && a[1].x == a[2].x)
        if (a[0].x == a[0].y + a[1].y + a[2].y) {
            cout << a[0].x << endl;
            fr(i1, 3)
                fr(i, a[i1].y) {
                    fr(j, a[i1].x)
                        cout << (char)('A' + i1);
                    cout << endl;}
            return 0;
    }
    fr(i, 100) {
        random_shuffle(a, a + 3);
        //while (next_permutation(a, a + 3))
            fr(mask, 8) {
                fr(i, 3)
                    if ((1 << i) & mask)
                        swap(a[i].x, a[i].y);
                check(a[0], a[1], a[2]);
                fr(i, 3)
                    if ((1 << i) & mask)
                        swap(a[i].x, a[i].y);
            }
    }
    cout << -1;



}