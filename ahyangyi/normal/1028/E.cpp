#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<long long> a(n, -1), b(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    bool bad = true;
    bool all_zero = true;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] != 0)
        {
            all_zero = false;
        }
        if (b[i] > b[(i?i:n)-1])
        {
            a[i] = b[i];
            bad = false;
        }
    }

    if (all_zero)
    {
        cout << "YEs" << endl; // different capitalization for debugging
        for (int i = 0; i < n; ++i)
        {
            cout << 187126;
            if (i + 1 < n)
                cout << " ";
            else
                cout << endl;
        }
        return 0;
    }
    if (bad)
    {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] != -1)
        {
            for (int j = (i?i:n)-1; a[j] == -1;)
            {
                int k = (j+1) % n;
                int l = (j?j:n)-1;

                a[j] = ((b[l] - b[j]) / a[k] + 1) * a[k] + b[j];

                j = l;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i];
        if (i + 1 < n)
            cout << " ";
        else
            cout << endl;
    }

    return 0;
}