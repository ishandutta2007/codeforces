#include <bits/stdc++.h>
using namespace std;


int n, Q;

int A[3][100005];
int a[100005];
int num;

main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> Q;
    for (int i = 1; i < n; i++)
        a[i] = 1;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= n; j++)
            A[i][j] = 1;
    while (Q--){
        int r, c;
        cin >> r >> c;
        if (A[r][c] == 0){
            if (c < n && a[c] == 0 && A[r][c + 1] == 1){
                a[c] = 1;
                num--;
            }
            if (c - 1 > 0 && a[c - 1] == 0 && A[r][c - 1] == 1){
                a[c - 1] = 1;
                num--;
            }
        }
        else {
            if (c < n && a[c] == 1 && A[3 - r][c] + A[3 - r][c + 1] < 2){
                num++;
                a[c] = 0;
            }
            if (c - 1 > 0 && a[c - 1] == 1 && A[3 - r][c - 1] + A[3 - r][c] < 2){
                num++;
                a[c - 1] = 0;
            }
        }
        A[r][c] ^= 1;
        if (num == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}