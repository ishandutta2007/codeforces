#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int n;
int ori[1000010];
int arr[1000010];

long long solve(long long d)
{
    for(int i = 0; i < n; i++)
        arr[i] = ori[i];

    for(int i = 0; i < n; i++)
        if(arr[i] > d + 2)
            arr[i] = (arr[i] - d - 2) % d + d + 2;

    long long res = 0;
    long long cur = 0;
    int mid = -1;
    int p = 0;
    for(int i = 0; i < n; i++)
    {
        if(cur + arr[i] < d)
        {
            cur += arr[i];
            if(mid == -1 && cur > d / 2)
                mid = i;
        }
        else
        {
            int tmp = arr[i] - (d - cur);

            arr[i] = d - cur;
            if(mid == -1)
                mid = i;

            for(int j = p; j <= i; j++)
                res += 1LL * abs(j - mid) * arr[j];

            cur = 0;
            mid = -1;
            arr[i] = tmp;
            p = i;
            i--;
        }
    }

    return res;
}

vector<long long> pv;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &ori[i]);

    long long sum = 0;
    for(int i = 0; i < n; i++)
        sum += ori[i];

    if(sum == 1)
    {
        puts("-1");
        return 0;
    }

    long long t = sum;
    for(int i = 2; 1LL * i * i <= sum; i++)
    {
        if(t % i == 0)
        {
            pv.push_back(i);
            t /= i;
            while(t % i == 0)
                t /= i;
        }
    }
    if(t > 1)
        pv.push_back(t);

    long long res = 1e18;
    for(long long d : pv)
        res = min(res, solve(d));

    printf("%lld\n", res);
    return 0;
}