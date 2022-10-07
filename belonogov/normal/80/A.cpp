#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

bool check (int k)
{
    int i;
    for (i = 2; i < k; i++)
        if (k % i == 0)
            return false;

    return true;
}


int main()
{
    int i, n, m;
    cin >> n >> m;
    if (! check(m))
    {
        cout << "NO";
        return 0;
    }
    for (i = n + 1; i < m; i++)
    {
        if (check(i))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}