#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e6 + 1;
const ll M = 1e3;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

struct pt {
    int x, y, num;
};

pt a[N];

bool cmp(pt a, pt b) {
    return a.x < b.x;
}

vector <pt> ar[M + 1][M + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i].x >> a[i].y;
        a[i].num = i + 1;
        ar[a[i].x / M][a[i].y / M].pb(a[i]);
    }
    fr(i, M + 1)
        fr(j, M + 1)
            sort(ar[i][j].begin(), ar[i][j].end(), cmp);

    pt last;
    ll s = 0;
    last.x = last.y = 0;
    while (1) {
        fr(i, M + 1) {
            if (i % 2 == 0)
                fr(j, M + 1) {
                    fr(k, ar[i][j].size()) {
                        //cout << ar[i][j][k].num << " ";
                        s += abs(ar[i][j][k].x - last.x) + abs(ar[i][j][k].y - last.y);
                        last = ar[i][j][k];
                    }
                }
            else
                for (int j = M; j >= 0; j--)
                    fr(k, ar[i][j].size()) {
                        //cout << ar[i][j][k].num << " ";
                        s += abs(ar[i][j][k].x - last.x) + abs(ar[i][j][k].y - last.y);
                        last = ar[i][j][k];
                    }
        }
        if (s >= 0 && s <= 2500000000) {
            fr(i, M + 1) {
            if (i % 2 == 0)
                fr(j, M + 1) {
                    fr(k, ar[i][j].size()) {
                        cout << ar[i][j][k].num << " ";
                        //s += abs(ar[i][j][k].x - last.x) + abs(ar[i][j][k].y - last.y);
                        //last = ar[i][j][k];
                    }
                }
            else
                for (int j = M; j >= 0; j--)
                    fr(k, ar[i][j].size()) {
                        cout << ar[i][j][k].num << " ";
                        //s += abs(ar[i][j][k].x - last.x) + abs(ar[i][j][k].y - last.y);
                        //last = ar[i][j][k];
                    }
            }
            return 0;
        }
    }
    //cout << s;



//    freopen("a.in", "w", stdout);
//    cout << 1000000 << endl;
//    fr(i, 1000000)
//        cout << ((rand() << 16) + rand()) % 1000000 << " " << ((rand() << 16) + rand()) % 1000000  << endl;
 }