#include <bits/stdc++.h>

using namespace std;

char a[1000][1000];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i< n; i++)
        for (int j =0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int qua = 0;
            for (int i1 = -1; i1 <= 1; i1++)
                for (int j1 = -1; j1 <=1; j1++)
                    if (abs(i1) + abs(j1) == 1)
                        if(a[i + i1][j + j1] == 'o')
                            qua++;
            if (qua % 2)
            {
                cout << "NO";
                return 0;
            }
        }
    cout << "YES";
    return 0;
}