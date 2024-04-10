#include <bits/stdc++.h>
using namespace std;
const int N = 4003;

int n;
vector<double> a;
int z;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; ++i)
    {
        double d;
        cin >> d;
        int dd = d;
        if (d - dd != 0)
            a.push_back(d - dd);
        else
            ++z;
    }
    double ans = n * n;
    for (int zz = 0; zz * 2 <= z; ++zz)
    {
        int zm = z - zz * 2;
        if (zm <= a.size())
        {
            double yans = 0;
            for (int i = 0; i < a.size(); ++i)
                yans += a[i];
            yans -= ((a.size() - zm) / 2);
            for (int i = 0; i <= zm; ++i)
                ans = min(ans, abs(yans - i));
        }
    }
    cout << ans << endl;
    return 0;
}