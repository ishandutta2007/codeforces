#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
using namespace std;

int main()
{   
    int n, m;
    cin >> n >> m;
    char ar[n][m];
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> ar[j][i];         
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << ar[i][j] << ar[i][j];
        cout << "\n";
        for (int j=0; j<m; j++)
            cout << ar[i][j] << ar[i][j];
        cout << "\n";
    }
}