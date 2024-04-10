#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAXM = 1000;

long long n, k;
long long odd, even;
int m;
long long a[MAXM];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    cin >> n >> k >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];

    if (k == 0 || k == n)
    {
        cout << string(m, k == 0? '.' : 'X') << endl;
        return 0;
    }


    if (n & 1)
    {
        k--;
        n--;
    }

    even = max(n + 2 - 2 * k, 2LL);
    odd = n + 1 - max(2 * (k - n / 2), 0LL);

    for (int i = 0; i < m; i++)
        printf("%c", 
            ((a[i] + even) & 1) == 0 && even <= a[i]? 'X' :
            ((a[i] + odd) & 1) == 0 && odd <= a[i]? 'X' : '.'
            );
    printf("\n");
    return 0;
}