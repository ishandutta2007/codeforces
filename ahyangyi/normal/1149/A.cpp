#include <iostream>
#include <vector>

using namespace std;

const char s[] = "ACTG";

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int ones = 0, twos = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            ++ones;
        }
        else
        {
            ++twos;
        }
    }
    if (ones > 0 && twos > 0)
    {
        cout << "2 1 ";
        --ones;
        --twos;
    }
    while (twos > 0)
    {
        cout << "2 ";
        --twos;
    }
    while (ones > 0)
    {
        cout << "1 ";
        --ones;
    }
    cout << endl;

    return 0;
}