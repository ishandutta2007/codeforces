#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
char a[N][N];
int r[N], c[N];

int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i< n; i++)
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '*') {
                cnt++;
                r[i]++;
                c[j]++;
            }
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(r[i] + c[j] - (a[i][j] == '*') == cnt) {
                cout << "YES\n" << i+1 << ' ' << j+1;
                return 0;
            }
    cout << "NO";
    return 0;
}