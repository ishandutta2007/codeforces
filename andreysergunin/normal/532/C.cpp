#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;

    if ((xv >= xp && yv >= yp) || (max(xv, yv) >= xp + yp))
        cout << "Polycarp\n";
    else
        cout << "Vasiliy\n";

    return 0;
}