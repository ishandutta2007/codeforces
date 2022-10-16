#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);

    int N, H;
    cin >> N >> H;

    vector <long double> sol;
    for (int i = 1; i < N; ++ i)
        sol.push_back(sqrtl(1.0L * i * H * H / N));

    cout << fixed << setprecision(20);
    for (int i = 0; i < sol.size(); ++ i)
        cout << sol[i] << " \n"[i + 1 == sol.size()];
    return 0;
}