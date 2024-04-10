#include <bits/stdc++.h>

using namespace std;

typedef long long li;

int f(int x)
{
    int ans = 0;
    if (x == 1)
        ans = 1;
    for (int i = 1; i < x; i++)
        if (__gcd(i, x - i) == 1)
            ans++;
        
    return ans;
}

int g(int x)
{
    int ans = 0;
    for (int d = 1; d <= x; d++)
        if (x % d == 0)
            ans += f(x / d);
    return ans;
}

void tau(int x)
{
    for (int i = 0; i < 20; i++)
    {
        if (i % 2 == 0)
            x = f(x);
        else
            x = g(x);
        
        printf("%d ", x);
    }
    printf("\n");
}

li phi(li x)
{
    vector<pair<li, int>> divs;
    
    for (li p = 2; p * p <= x; p++)
        if (x % p == 0)
        {
            int power = 0;
            while (x % p == 0)
            {
                power++;
                x /= p;
            }
            
            divs.emplace_back(p, power);
        }
        
    if (x != 1)
        divs.emplace_back(x, 1);
    
    li answer = 1;
    for (auto it: divs)
    {
        answer *= it.first - 1;
        for (int i = 0; i < it.second - 1; i++)
            answer *= it.first;
    }
    
    //printf("phi(%lld) is %lld\n", x, answer);
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    li n, k;
    cin >> n >> k;
    
    li times = (k + 1) / 2;
    for (int i = 0; i < times; i++)
    {
        n = phi(n);
        
        if (n == 1)
            break;
    }
    
    cout << n % (li)(1e9 + 7) << endl;
    
    return 0;
}