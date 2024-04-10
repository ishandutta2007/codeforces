#include <iostream>

using namespace std;

int mat[505][505];

int main()
{
    int n, k;
    cin >> n >> k;

    int first = 1, last = n * n;
    long long int sum = 0;

    for (int i = n; i; -- i) {
        for (int j = n; j >= k; -- j)
            mat[i][j] = last --;
        for (int j = 1; j < k; ++ j)
            mat[i][j] = first ++;

        sum += mat[i][k];
    }

    cout << sum << '\n';
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            cout << mat[i][j] << " \n"[j == n];
    return 0;
}