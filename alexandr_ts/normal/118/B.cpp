#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[100][100];

void f(int x, int y, int k)
{
    if(k < 0 || x * y < 0 || x > 2 * n || y > 2 * n)
        return;
    a[x][y] = k;
    if(a[x][y - 1] < k - 1)
        f(x, y - 1, k - 1);
    if(a[x][y + 1] < k - 1)
        f(x, y + 1, k - 1);
    if(a[x - 1][y] < k - 1)
        f(x - 1, y, k - 1);
    if(a[x + 1][y] < k - 1)
        f(x + 1, y, k - 1);
}

int main()
{
    cin >> n;
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            a[i][j] = -1;
    f(n, n, n);
    int qua = 0;
    int er = 0;
    for(int i = 0; i <= 2 * n; i++)
    {

        for(int j = 0; j <= 2 * n; j++)
        {
            if(a[i][j] == 0)
            {
                qua++;
                if(qua % 2 == 1 || qua == 4 * n)
                    er = 1;
            }
            if(a[i][j] == -1)
                cout << "  ";
            else
                if(er != 1)
                    cout << a[i][j] << " ";
                else
                    cout << a[i][j];
            if(er == 1)
            {
                er = 0;
                break;
            }
        }
        if(i != 2 * n)
            cout << endl;
    }
    return 0;
}