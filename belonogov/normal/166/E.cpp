#include <iostream>
#include <cstdio>

using namespace std;
const long long p = 1e9 + 7;
long long a[4][2];

int main(){
    int i, n, j, k;
    cin >> n;
    a[0][0] = 1;
    for (i = 1; i <= n; i++){
        for (j = 0; j < 4; j++)
            for (k = 0; k < 4; k++)
                if (k != j)
                    a[k][1] = (a[k][1] + a[j][0]) % p;
        for (j = 0; j < 4; j++){
            a[j][0] = a[j][1];
            a[j][1] = 0;
        }
    }

    cout << a[0][0];
    return 0;
}