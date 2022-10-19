#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double h;
    cin >> n >> h;
    for (int i=1;i<n;i++)
    {
        cout << setprecision(10) << fixed <<  h*sqrt(i)/sqrt(n) << " ";
    }
}