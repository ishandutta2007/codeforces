#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

struct gauss {
    vector< vector<double> > data;
    int ec, rez;
    const double eps = 1e-11;
    vector<double> solutions;

    bool equal(double a, double b) {
        a -= b;
        if (a < -eps || eps < a) return false;
        return true;
    }

    void init(int _ec, int _var) {
        ec = _ec; rez = _var + 1;
        data = vector< vector<double> >(ec + 3, vector<double>(rez + 3, 0));
    }

    void print_data() {
        int i, j;
        for (i = 1; i <= 10; i++) {
            for (j = 1; j <= 10; j++) cerr << data[i][j] << ' ';
            cerr << " = " << data[i][rez];
            cerr << "\n";
        }
        cerr << '\n';
    }

    void rm_gauss() {
        int i, j, k, l;

        i = 1; j = 1;
        while (i <= ec && j < rez) {
            int found = 0;
            for (k = i; k <= ec; k++)
                if (!equal(data[k][j], 0.00))
                    {found = k; break;}

            if (!found) {
                j++;
                continue;
            }

            swap(data[i], data[found]);
            for (k = i + 1; k <= ec; k++) {
                if (equal(data[k][j], 0.00)) continue;

                double delta = data[k][j] / data[i][j];
                for (l = j; l <= rez; l++) data[k][l] -= data[i][l] * delta;
            }

            //print_data();

            i++; j++;
        }
    }

    bool solve() {
        int i, j, k;

        rm_gauss();
        solutions = vector<double>(rez + 3, 0.00);

        //print_data();

        for (i = ec; i > 0; i--) {
            for (j = 1; j < rez && equal(data[i][j], 0.00); j++);
            if (j == rez) {
                if (!equal(data[i][rez], 0.00)) return false;
                continue;
            }

            int pos = j;
            solutions[pos] = data[i][rez];

            for (j++; j < rez; j++) {
                if (equal(data[i][j], 0.00)) continue;
                solutions[pos] -= data[i][j] * solutions[j];
            }

            solutions[pos] /= data[i][pos];
        }

        return true;
    }
};

int i;
gauss work;
vector<int> in, out;
vector<int> sol, aux;

pair<int, int> ask(int a, int b, int c, int d) {
    int bulls, cows;

    printf("%d%d%d%d\n", a, b, c, d);
    fflush(stdout);

    scanf("%d%d", &bulls, &cows);
    if (bulls == 4 && cows == 0) exit(0);

    return mp(bulls, cows);
}

pair<int, int> ask_debug(int a, int b, int c, int d) {
    int bulls, cows, i, j;
    vector<int> v1 = {1, 7, 2, 9};
    vector<int> v2 = {a, b, c, d};

    bulls = cows = 0;
    for (i = 0; i < 4; i++)
        if (v1[i] == v2[i])
            bulls++;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (v1[i] == v2[j])
                cows++;


    printf("%d%d%d%d\n", a, b, c, d);
    fflush(stdout);
    printf("%d %d\n", bulls, cows - bulls);

    return mp(bulls, cows - bulls);
}

int ch(int x) {
    if (x > 10)
        x -= 10;
    return x;
}

int main()
{
    work.init(10, 10);
    for (i = 1; i <= 10; i++) work.data[10][i] = 1;
    work.data[10][11] = 4;

        auto aux2 = ask(0, 1, 2, 4);

        work.data[1][1] = 1;
        work.data[1][2] = 1;
        work.data[1][3] = 1;
        work.data[1][5] = 1;
        work.data[1][11] = aux2.first + aux2.second;

    for (i = 0; i < 8; i++) {
        auto aux = ask(i, i + 1, (i + 2) % 10, (i + 3) % 10);

        work.data[i + 2][i + 1] = 1;
        work.data[i + 2][i + 2] = 1;
        work.data[i + 2][ch(i + 3)] = 1;
        work.data[i + 2][ch(i + 4)] = 1;
        work.data[i + 2][11] = aux.first + aux.second;
    }

    if (!work.solve()) cerr << "err";

    for (i = 1; i <= 10; i++) {
        if (work.equal(work.solutions[i], 0.00))
            out.pb(i - 1);
        else
            in.pb(i - 1);
    }

    out.resize(4);

    for (i = 0; i < 4; i++) {
        for (int j = 0; j < in.size(); j++) {
            aux = out;
            aux[i] = in[j];

            if (ask(aux[0], aux[1], aux[2], aux[3]).first == 1) {
                sol.pb(in[j]);
                in[j] = in.back();
                in.pop_back();
                break;
            }
        }
    }

    ask(sol[0], sol[1], sol[2], sol[3]);


    return 0;
}