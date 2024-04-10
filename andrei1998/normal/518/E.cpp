#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <vector>
#include <utility>

#define inf 1100000007ll
#define int long long int
using namespace std;

char sir[4000005];
int poz;
int lung;

inline void cit () {
    cin.get();
    cin.get(sir + 1, 4000005);

    poz = 1;
    lung = strlen(sir + 1);
}

inline int gett () {
    int ans = 0;
    while (poz <= lung && sir[poz] == ' ')
        poz ++;

    if (sir[poz] == '?') {
        poz ++;
        return (inf + 1);
    }

    int semn = 1;
    if (sir[poz] == '-') {
        poz ++;
        semn = -1;
    }

    while (poz <= lung && isdigit(sir[poz])) {
        ans *= 10;
        ans += sir[poz] - '0';
        poz ++;
    }

    return semn * ans;
}

int gauss (int n) {
    return (n * (n + 1ll) / 2);
}

int suma (int st, int dr) {
    if (st >= 0) {
        return gauss(dr) - gauss(st - 1);
    }
    else if (dr <= 0) {
        st *= -1;
        dr *= -1;

        swap(st, dr);

        return gauss(dr) - gauss(st - 1);
    }
    else {
        return suma(st, 0) + suma(0, dr);
    }
}

int best (int lung, int st, int dr) {
    if (dr - st + 1 < lung)
        return inf + 7;

    int st_best = st;
    int ans_best = suma(st, st + lung - 1);

    if (suma(dr - lung + 1, dr) < ans_best) {
        st_best = dr - lung + 1;
        ans_best = suma(dr - lung + 1, dr);
    }

    int st_aux = - (lung - 1) / 2;
    int dr_aux = lung / 2;

    if (st_aux >= st && dr_aux <= dr) {
        if (suma(st_aux, dr_aux) < ans_best) {
            st_best = st_aux;
            ans_best = suma(st_aux, dr_aux);
        }
    }

    return st_best;
}

int v[100005];

vector <int> vects[100005];
vector <int> spec[100005];

inline bool create (vector<int> &v, vector<int> &spec) {
    for (int i = 0; i < v.size(); i++)
        if (v[i] != inf + 1)
            spec.push_back(i);

    for (int i = 1; i < spec.size(); i++)
        if (v[spec[i - 1]] >= v[spec[i]])
            return false;

    int y;
    int j, k;
    for (int i = 1; i < spec.size(); i++) {
        if (spec[i] - spec[i - 1] - 1 > 0) {
            y = best(spec[i] - spec[i - 1] - 1, v[spec[i - 1]] + 1, v[spec[i]] - 1);

            if (y == inf + 7)
                return false;

            for (j = spec[i - 1] + 1, k = y; j <= spec[i] - 1; j++, k++)
                v[j] = k;
        }
    }

    return true;
}

signed main()
{
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    cit();
    for (int i = 1; i <= n; i++)
        v[i] = gett();

    for (int i = 0; i < k; i++)
        vects[i].push_back(-inf);

    for (int i = 1; i <= n; i++)
        vects[i % k].push_back(v[i]);

    for (int i = 0; i < k; i++)
        vects[i].push_back(inf);

    for (int i = 0; i < k; i++)
        if (!create(vects[i], spec[i])) {
            cout << "Incorrect sequence\n";
            return 0;
        }

    for (int i = 1; i <= n; i++) {
        v[i] = vects[i % k][(i - 1) / k + 1];
    }

    for (int i = 1; i <= n; i++)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}