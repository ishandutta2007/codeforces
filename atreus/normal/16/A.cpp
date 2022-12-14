#include <iostream>

using namespace std;

int main () {
    long long n, m, h = 0, l = 0;
    cin >> n >> m;
    string k[n];
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int j = 0; j < n - 1; j++)
        if (k[j] == k[j + 1])
            l++;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m - 1; i++)
            if (k[j][i] != k[j][i + 1])
                h++;
    if (h >= 1 || l >= 1)
        cout << "NO" << endl;
    else
        cout << "Yes" << endl;
}