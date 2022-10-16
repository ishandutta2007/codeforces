#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long int lint;

struct Line {
    int A, B;
    lint C;
    Line(const int &X1, const int &Y1, const int &X2, const int &Y2) {
        A = Y2 - Y1;
        B = X1 - X2;
        C = 1LL * X2 * Y1 - 1LL * X1 * Y2;
    }

    long double dist(const int &X, const int &Y) {
        return fabsl(1LL * A * X + 1LL * B * Y + C) / sqrtl(1LL * A * A + 1LL * B * B);
    }
};

const int NMAX = 1000 + 5;

int N;
int x[NMAX];
int y[NMAX];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> x[i] >> y[i];

    long double ans = -100;
    for (int i = 1; i <= N; ++ i) {
        Line l(x[i % N + 1], y[i % N + 1],
               x[(i - 1 + N - 1) % N + 1], y[(i - 1 + N - 1) % N + 1]);
        long double aux = l.dist(x[i], y[i]);

        if (ans < -10 || aux < ans)
            ans = aux;
    }

    cout << fixed << setprecision(10) << ans / 2.0 << '\n';
    return 0;
}