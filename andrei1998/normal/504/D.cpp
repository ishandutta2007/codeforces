#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
#include <cstdio>

using namespace std;

const int base = 100000000;

class big_int {
public:
    int v[80];

    big_int(int c = 0) {
        memset(v, 0, sizeof v);

        v[0] = 1;
        v[1] = c;
    }

    int div2() {
        big_int ans;
        ans.v[0] = v[0];

        int r = 0;
        for (int i = v[0]; i; -- i) {
            ans.v[i] = (r * base + v[i]) / 2;
            r = (r * base + v[i]) % 2;
        }

        while (ans.v[0] > 1 && !ans.v[ans.v[0]])
            -- ans.v[0];

        (*this) = ans;

        return r;
    }
};

istream& operator>>(istream &f, big_int &x) {
    char sir[605];
    cin.get(sir + 1, 605); cin.get();

    int n = strlen(sir + 1);
    reverse(sir + 1, sir + n + 1);

    x.v[0] = 0;
    for (int i = 1; i <= n; i += 8) {
        int nr = 0;
        for (int j = min(n, i + 7); j >= i; -- j) {
            nr *= 10;
            nr += (sir[j] - '0');
        }

        x.v[++ x.v[0]] = nr;
    }

    return f;
}

ostream& operator<<(ostream& g, const big_int &x) {
    for (int i = x.v[0]; i; -- i)
        cout << x.v[i];
    return g;
}

class Gauss {
public:
    int n;
    bitset <4005> mat[2005];

    int pivot_line[2005];
} g;

vector <int> ans;

int main()
{
    int n = 0;
    cin >> n; cin.get();

    for (int i = 1; i <= n; ++ i) {
        big_int x;
        cin >> x;

        ++ g.n;

        g.mat[g.n] &= 0;

        int pos = 2000;
        while (x.v[0] > 1 || x.v[1] > 0)
            g.mat[g.n][pos --] = x.div2();

        g.mat[g.n][2000 + i] = 1;

        //Gauss-ul
        bool ok = false;
        for (int j = 1; j <= 2000; ++ j) {
            if (g.mat[g.n][j] == 1) {
                if (g.pivot_line[j])
                    g.mat[g.n] ^= g.mat[g.pivot_line[j]];
                else {
                    ok = true;
                    g.pivot_line[j] = g.n;

                    for (int k = 1; k < g.n; ++ k)
                        if (g.mat[k][j])
                            g.mat[k] ^= g.mat[g.n];
                    break;
                }
            }
        }

        //Afisarea
        if (!ok) {
            ans.clear();
            for (int j = 1; j < i; ++ j)
                if (g.mat[g.n][2000 + j])
                    ans.push_back(j - 1);
            -- g.n;

            cout << (int)ans.size();
            for (int j = 0; j < ans.size(); ++ j) {
                cout << ' ';
                cout << (int)ans[j];
            }
        }
        else
            cout << '0';
        cout << '\n';
    }

    return 0;
}