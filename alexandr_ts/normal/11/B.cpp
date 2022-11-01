#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 0)
        n = -n;
    int curnum = 0;
    int cursum = 0;
    int quaodd = 0;
    while ((cursum < n) || ((quaodd % 2) != (n % 2)))
    {
        curnum++;
        cursum += curnum;
        if (curnum % 2 != 0)
            quaodd++;
    }
    cout << curnum;
    return 0;
}