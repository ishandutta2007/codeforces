#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int MAX = 32000000;

int ipow(int x, int y)
{
    if(y == 0)
        return 1;
    if(y % 2)
        return 1LL * x * ipow(x, y - 1) % mod;
    int t = ipow(x, y / 2);
    return 1LL * t * t % mod;
}

int inv(int x)
{
    return ipow(x, mod - 2);
}

struct str
{
    long long p;
    int e;
};

bool chk[MAX + 1];
int mem[51][51];

int invm[51];

int main()
{
    long long n;
    int m, i, j, k;
    scanf("%lld%d", &n, &m);

    for(i = 1; i <= 50; i++)
        invm[i] = inv(i);

    vector<str> v;
    for(i = 2; i <= MAX; i++)
    {
        if(!chk[i])
        {
            int cnt = 0;
            while(n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if(cnt)
                v.push_back({ i, cnt });

            if(1LL * i * i <= MAX)
                for(j = i * i; j <= MAX; j += i)
                    chk[j] = 1;
        }
    }
    if(n)
        v.push_back({ n, 1 });

    for(i = 1; i < 50; i++)
    {
        mem[i][i] = 1;
        for(j = 0; j < m; j++)
            for(k = i; k >= 0; k--)
                mem[i][k] = (mem[i][k + 1] + 1LL * mem[i][k] * invm[k + 1]) % mod;
    }

    int res = 1;
    for(str s : v)
    {
        int c = 0;
        for(i = 0; i <= s.e; i++)
            c = (c + 1LL * ipow(s.p % mod, i) * mem[s.e][i]) % mod;
        
        res = 1LL * res * c % mod;
    }

    printf("%d\n", res);
    return 0;
}