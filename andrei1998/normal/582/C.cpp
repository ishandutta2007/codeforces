#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

const int NMAX = 200005;

int n;
int v[NMAX];

int pos;
int divs[205];

map <int, int> where;

void desc () {
    for (int i = 1; i * i <= n; ++ i)
        if (n % i == 0) {
            divs[++ pos] = i;

            if (i * i != n)
                divs[++ pos] = n / i;
        }
    sort(divs + 1, divs + pos + 1);

    for (int i = 1; i <= pos; ++ i)
        where[divs[i]] = i;
}

int maxime[162][NMAX];
//bool ok[162][NMAX];
int at_most[162][NMAX];

//vector <int> at_mosts[162];

inline int _next (int x) {
    if (x + 1 == n)
        return 0;
    return x + 1;
}

int frecv[NMAX];

void precalc () {
    int j;
    for (int i = 1; i <= pos; ++ i) {
        //cout << "muncesc " << i << ' ' << divs[i] << endl;
        for (j = 0; j < n; ++ j)
            maxime[i][j % divs[i]] = max(maxime[i][j % divs[i]], v[j]);
        //for (j = 0; j < n; ++ j)
        //    ok[i][j] = (v[j] == maxime[i][j % divs[i]]);

        int dr = 0;
        for (j = 0; j < n; ++ j)
            if ((v[j] == maxime[i][j % divs[i]])) {
                while (_next(dr) != j && (v[_next(dr)] == maxime[i][_next(dr) % divs[i]]))
                    dr = _next(dr);

                at_most[i][j] = (dr - j + n) % n + 1;
            }
            else {
                dr = (j + 1) % n;
                at_most[i][j] = 0;
            }

        //for (j = 0; j < n; ++ j)
        //    if (at_most[i][j])
        //        at_mosts[i].push_back(at_most[i][j]);

        //sort(at_most[i], at_most[i] + n);
        for (j = 0; j <= n; ++ j)
            frecv[j] = 0;
        for (j = 0; j < n; ++ j)
             frecv[at_most[i][j]] ++;

        int pos = 0;
        for (j = 0; j < n; ++ j)
            while (frecv[j] --)
                at_most[i][pos ++] = j;

        /*cout << "maximele sunt " << endl;
        for (j = 0; j < divs[i]; ++ j)
            cout << maxime[i][j] << ' ';
        cout << endl;

        cout << "at_mostS e " << endl;
        for (j = 0; j < n; ++ j)
            cout << at_most[i][j] << ' ';
        cout << endl;*/
    }
}

int gcd (int a, int b) {
    int r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n; ++ i)
        cin >> v[i];

    desc();
    precalc();

    int d, which;
    long long int ans = 0;
    for (int i = 1; i < n; ++ i) {
        d = gcd(i, n);
        which = where[d];

        //cout << "cu " << i << ' ' << at_mosts[which].end() - lower_bound(at_mosts[which].begin(), at_mosts[which].end(), i) << endl;
        ans += (at_most[which] + n - lower_bound(at_most[which], at_most[which] + n, i));
    }

    cout << ans << '\n';
    return 0;
}