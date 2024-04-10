#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int NMAX = 200005;

int n;
int v[NMAX];

double get_ans (double x) {
    double minim = v[1] - x;
    double maxim = v[1] - x;

    double dp_min = v[1] - x;
    double dp_max = v[1] - x;

    for (int i = 2; i <= n; ++ i) {
        if (dp_max < 0)
            dp_max = 0;
        if (dp_min> 0)
            dp_min = 0;

        dp_max += (v[i] - x);
        dp_min += (v[i] - x);

        if (dp_min < minim)
            minim = dp_min;
        if (dp_max > maxim)
            maxim = dp_max;
    }

    //cout << "vine" << minim << ' ' << maxim << endl;
    return max(abs(minim), abs(maxim));
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    get_ans(0);

    double left = -10505.0;
    double right = 10505.0;

    double m1, m2;

    for (int steps = 0; steps < 100; ++ steps) {
        m1 = (2 * left + right) / 3;
        m2 = (left + 2 * right) / 3;

        if (get_ans(m1) > get_ans(m2))
            left = m1;
        else
            right = m2;
    }

    cout << fixed << setprecision(15) << get_ans(left) << '\n';
    return 0;
}