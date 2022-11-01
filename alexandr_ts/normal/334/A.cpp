#include <bits/stdc++.h>

using namespace std;

vector <int> a[1000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < (n / 2); i++)
    {
        for (int j = 1; j <= n; j++)
            a[j].push_back(2 * n * i + j);
        for (int j = n; j >= 1; j--)
            a[j].push_back(n * (2 * i + 1) + n - j + 1);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < a[i].size(); j++)
            cout << a[i][j] << " ";cout << endl;}
    return 0;
}