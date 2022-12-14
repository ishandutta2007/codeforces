#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int colmi[k], colma[k];
    for(int i = 0; i < k; ++i)
    {
        colmi[i] = 1000;
        colma[i] = -1000;
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < k; ++j)
        {
            int c = (a[i] - j) / k + ((a[i] - j) % k != 0);
            if(c < colmi[j])
                colmi[j] = c;
            if(c > colma[j])
                colma[j] = c;
        }
    }
    for(int i = 0; i < k; ++i)
    {
        if(colma[i] - colmi[i] > 1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; ++i)
    {
        int c = 0;
        for(int j = 0; j < a[i]; ++j)
        {
            cout << c + 1 << " ";
            c = (c + 1) % k;
        }
        cout << endl;
    }
}