#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const int M = 1999;
const int K = 1000;
const int N = 1e5 + 3;

struct Q {
    int val, nxt;
};

bool cmp(Q a, Q b) {
    return a.val < b.val;
}

pair <int, int> answ[N];

int main() {
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    vector <Q> v;
    int n, st, x;
    cin >> n >> st >> x;
    fill(answ, answ + n + 2, mp(-2, -2));

    cout << "? " << st << endl;
    int valSt, nextSt;
    cin >> valSt >> nextSt;
    v.pb({valSt, nextSt});
//    if (valSt > x) {
//        cout << "! -1" << endl;
//        return 0;
//    }
    int total = 1;

    fr(i1, K) {
        int i = ((ll)rand() + (ll)rand()) % (ll)n + 1;
        assert(i >= 1 && i <= n);
        int val1, next1;
        if (answ[i] != make_pair(-2, -2))
            val1 = answ[i].first, next1 = answ[i].second;
        else {
            cout << "? " << i << endl;
            total++;
            cin >> val1 >> next1;
            answ[i] = mp(val1, next1);
        }
        v.pb({val1, next1});
    }

    sort(v.begin(), v.end(), cmp);
    int cur = -1;
    fr(i, v.size())
        if (v[i].val < x && (i + 1 == (int)v.size() || v[i + 1].val >= x)) {
            cur = i;
            break;
        }

    if (cur == -1) {
        cout << "! " << valSt << endl;
        return 0;
    }

    int ans = -1;
    int curq = v[cur].nxt;


    while (curq != -1) {
        if (total == M) break;
        //assert(total <= M);

        int val1, next1;

        if (answ[curq] != make_pair(-2, -2))
            val1 = answ[curq].first, next1 = answ[curq].second;
        else {
            cout << "? " << curq << endl;
            total++;
            cin >> val1 >> next1;
            answ[curq] = mp(val1, next1);
        }

        if (val1 >= x) {
            cout << "! " << val1 << endl;
            return 0;
        }
        if (next1 == -1) break;
        curq = next1;
    }
    cout << "! -1" << endl;
    return 0;
}