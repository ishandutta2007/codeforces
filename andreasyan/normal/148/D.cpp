#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int w, b;

double a[N][N][2];
bool c[N][N][2];
void rec(int w, int b, int h)
{
    c[w][b][h] = true;
    if (h == 0)
    {
        if (w + b == 0)
        {
            return;
        }
        a[w][b][h] = (1.0 * w / (w + b));

        if (b > 0 && !c[w][b - 1][h ^ 1])
            rec(w, b - 1, h ^ 1);
        if (b > 0)
        {
            a[w][b][h] += (1.0 * b / (w + b)) * (1.0 - a[w][b - 1][h ^ 1]);
        }
    }
    else
    {
        if (w + b <= 2)
        {
            a[w][b][h] = 1.0;
            return;
        }
        a[w][b][h] = (1.0 * w / (w + b));

        if (b > 0 && w > 0 && !c[w - 1][b - 1][h ^ 1])
            rec(w - 1, b - 1, h ^ 1);
        if (b > 0 && w > 0)
        {
            a[w][b][h] += (1.0 * b / (w + b)) * (1.0 * w / (w + b - 1)) * (1.0 - a[w - 1][b - 1][h ^ 1]);
        }

        if (b > 1 && !c[w][b - 2][h ^ 1])
        {
            rec(w, b - 2, h ^ 1);
        }
        if (b > 1)
        {
            a[w][b][h] += (1.0 * b / (w + b)) * (1.0 * (b - 1) / (w + b - 1)) * (1.0 - a[w][b - 2][h ^ 1]);
        }
    }
}

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    cin >> w >> b;
    rec(w, b, 0);
    cout << a[w][b][0] << endl;
    return 0;
}