#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1001ll;
const ll MOD = 1000000007ll;

bool prime[N];

set <ll> divs;
set <ll> :: iterator it;

char a[N][N];
int b[N];

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '.')
                if ((i + j) % 2)
                    a[i][j] = 'W';
                else
                    a[i][j] = 'B';
        }
    for (int i = 0; i< n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j]; cout << endl;}
}