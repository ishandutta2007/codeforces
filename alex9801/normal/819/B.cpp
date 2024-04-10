#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int arr[1000010];
int pos[1000010];
long long sum[1000010];
long long dif[1000010];

int main()
{
    int n, p, k, i;
    long long a, r, c;
    scanf("%d", &n);
    for(i = 1; i<=n; i++)
        scanf("%d", &arr[i]);

    a = 0;
    for(i = 1; i<=n; i++)
        pos[arr[i]] = i;

    for(i = 1; i<=n; i++)
    {

        p = i;
        i = pos[i];

        if(i < p)
        {
            a++;
            dif[i-1] -= (p-1) - (n-p) - 1;
            sum[i-1] -= 2;
            sum[i + n-p] += 2;
        }
        else if(i > p)
        {
            a--;
            sum[i-p] += 2;
            dif[i-1] -= (p-1) - (n-p) - 1;
            sum[i-1] -= 2;
        }
        else
        {
            a++;
            sum[i-1] -= 2;
            dif[i-1] += (n-p) - (p-1) + 1;
        }

        i = p;
    }

    r = 0;
    k = 0;
    for(i = 1; i<=n; i++)
        r += abs(i-pos[i]);
    
    c = r;
    a += sum[0];
    c += dif[0];
    for(i = 1; i<n; i++)
    {
        c += a;
        if(c < r)
        {
            r = c;
            k = i;
        }
        a += sum[i];
        c += dif[i];
    }
    printf("%lld %d\n", r, (n-k)%n);
    return 0;
}