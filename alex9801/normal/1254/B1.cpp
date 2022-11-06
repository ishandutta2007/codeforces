#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;
int arr[1000010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    
    if(sum == 1)
    {
        puts("-1");
        return 0;
    }

    long long res = INF;
    for(int i = 2; i <= sum; i++)
    {
        if(sum % i != 0)
            continue;

        vector<int> v;
        long long t = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == 0)
                continue;

            v.push_back(j);
            if((int)v.size() == i)
            {
                for(int x : v)
                    t += abs(x - v[i / 2]);

                v.clear();
            }
        }
        assert(v.empty());
        res = min(res, t);
    }
    assert(res != INF);
    
    printf("%lld\n", res);
    return 0;
}