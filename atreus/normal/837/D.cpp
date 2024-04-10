#include <iostream>
#include <fstream>
using namespace std;
int n, k, sol, v5[204], v2[203];
long long x;
int d[203][6005];
int main () {
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
            for (int l = 0;l <= 6000; l++) {
                d[i][l] = -100000000 ;
            }
    d[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        while (x%2 == 0) {
            x/=2;
            v2[i]++;
        }
        while (x%5 ==0) {
            x/=5;
            v5[i]++;
        }
        for (int j =k ;j >= 1; j--) {
            for (int l = v5[i]; l <= 6000; l++)
                d[j][l] = max(d[j - 1][l-v5[i]] + v2[i], d[j][l]);
        }

    }
    


    

    for (int i = 1; i <= 6000; i++) {
        sol = max(sol, min(i, d[k][i]));
    }
    cout << sol;

    return 0;
}