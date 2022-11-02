#include <bits/stdc++.h>

using namespace std;

string a[2000];
bool nes[2000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int e = 0; e < m; e++)
    {
        int k = 0;
        int id;
        for (int i = 0; i < n; i++)
        {
            if (a[i][e] == '1')
            {
                k++;
                id = i;
            }
        }
        if (k == 1)
            nes[id] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!nes[i])
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}