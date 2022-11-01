#include <iostream>
#include <cmath>

using namespace std;

const long double EPS = 1e-9;

int main()
{
    int n;
    cin >> n;
    int temp;
    bool wr = false;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        for(int j = 3; j < 10000; j++)
            if(fabs((180.0 * (j - 2.0) / j) - (180 * (j - 2) / j)) < EPS && temp == 180 * (j - 2) / j)
                wr = true;
        if(!wr)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        wr = false;
    }
    return 0;
}