#include <iostream>
using namespace std;

int MAGIC = 1000000007;
int C[4001][4001], M[4001], D[4001];

int main ()
{
    int n;
    cin >> n;

    for (int i = 0; i <= 4000; ++i)
        for (int j = 0; j <= i; ++j)
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MAGIC;
    
    M[0] = 1;
    D[0] = 0;
    for (int i = 1; i <= 4000; ++i)
    {
        M[i] = 0;
        D[i] = (M[i - 1] + D[i - 1]) % MAGIC;
        for (int j = 1; j <= i; ++j)
        {
            M[i] = (M[i] + M[i - j] * (long long)C[i - 1][j - 1]) % MAGIC;
            D[i] = (D[i] + D[i - j] * (long long)C[i - 1][j - 1]) % MAGIC;
        }
    }

    cout << D[n] << endl;

    return 0;
}