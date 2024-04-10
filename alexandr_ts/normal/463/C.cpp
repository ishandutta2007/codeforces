#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[3000][3000];
ll d1[10000];
ll d2[10000];
ll ans[3000][3000];

int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            d1[i - j + 3000] += a[i][j];
            d2[i + j] += a[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = d1[i - j + 3000] + d2[i + j] - a[i][j];
        }
    ll maxodd = -10000000000000000;
    ll maxeven = -10000000000000000;
    ll posoddx = -1, posoddy = -1, posevenx = -1, poseveny = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i + j) % 2)
            {
                if (maxodd < ans[i][j]) {
                    posoddx = i;
                    posoddy = j;
                }
                maxodd = max(maxodd, ans[i][j]);
            }
            else
            {
                if (maxeven < ans[i][j]) {
                    posevenx = i;
                    poseveny = j;
                }
                maxeven = max(maxeven, ans[i][j]);
            }
    cout << maxodd + maxeven << endl << posoddx + 1 << " " << posoddy + 1<< " " << posevenx+ 1 << " " << poseveny + 1;
    return 0;
}