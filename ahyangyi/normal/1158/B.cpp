#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    if (n < k * 3)
    {
        int cycle = (n - k) / 2 + 1;
        for (int i = 0; i < n; ++i)
            cout << int(i % cycle == cycle - 1);
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; ++i)
            if (i < k)
                cout << 0;
            else
                if (k == 1)
                    cout << 1;
                else
                    cout << int((i - k) % (k - 1) == 0);
        cout << endl;
    }

    return 0;
}