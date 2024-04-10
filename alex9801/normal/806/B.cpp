#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int arr[120][5];
int a[5];

int l[6] = { 32, 16, 8, 4, 2, 1 };
int c[6] = { 3000, 2500, 2000, 1500, 1000, 500 };

vector<int> can;

const int MAX = 1000000007;

int main()
{
    int n, p, q, t, r1, r2, i, j;
    scanf("%d", &n);
    for(i = 0; i<n; i++)
        for(j = 0; j<5; j++)
            scanf("%d", &arr[i][j]);

    for(i = 0; i<n; i++)
        for(j = 0; j<5; j++)
            if(arr[i][j] != -1)
                a[j]++;

    can.push_back(0);
    can.push_back(1);
    for(i = 0; i<5; i++)
    {
        for(j = 0; j<6; j++)
        {
            can.push_back(a[i]*l[j] - n);
            if(l[j] != 1)
                can.push_back((n-a[i])/(l[j]-1) + 1);
        }
    }

    sort(can.begin(), can.end());

    for(int &x: can)
    {
        if(x < 0 || x > MAX)
            continue;

        r1 = r2 = 0;
        for(i = 0; i<5; i++)
        {
            if(arr[0][i] == -1 && arr[1][i] == -1)
                continue;

            p = a[i];
            q = n + x;
            if(arr[0][i] != -1 && arr[1][i] != -1 && arr[0][i] > arr[1][i])
                p += x;

            for(j = 0; j<6; j++)
            {
                if(1LL*p*l[j] <= q)
                {
                    t = c[j];
                    break;
                }
            }

            if(arr[0][i] != -1)
                r1 += t/250 * (250 - arr[0][i]);
            if(arr[1][i] != -1)
                r2 += t/250 * (250 - arr[1][i]);
        }

        if(r1 > r2)
        {
            printf("%d", x);
            return 0;
        }
    }

    printf("-1");
    return 0;
}