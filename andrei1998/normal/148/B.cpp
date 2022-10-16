#include <iostream>

using namespace std;

int main()
{
    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;

    if (vd < vp) {
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    double where = vp * t;

    while (1) {
        double t_chase = 1.0 * where / (vd - vp);
        double new_where = where + t_chase * vp;

        if (new_where >= c - 1e-10)
            break;
        else {
            ++ans;
            where = new_where + (t_chase + f) * vp;
        }
    }

    cout << ans << '\n';
    return 0;
}