#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;

typedef long long ll;

int f(const vector<int>& a)
{
    int n = (int)a.size();
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        int m = n;
        for (int j = i; j < n; j++)
        {
            m = min(m, a[j]);
            sum += m;
        }
    }
    
    return sum;
}

void confirm(const vector<int>& a)
{
    int n = (int)a.size();
    
    vector<int> ra(n);
    for (int i = 0; i < n; i++)
        ra[a[i] - 1] = i;
    
    int low = 0, high = n - 1;
    for (int i = 0; i < n; i++)
    {
        assert(ra[i] == low || ra[i] == high);
        
        if (ra[i] == low) low++;
        if (ra[i] == high) high--;
    }
}

vector<int> solve(ll n, ll m)
{
    if (n == 1)
    {
        assert(m == 1);
        return vector<int> { 1 };
    }
    
    if (m <= (1ll << (n - 2)))
    {
        vector<int> ans = solve(n - 1, m);
        for (auto& x: ans) x++;
        ans.insert(ans.begin(), 1);
        return ans;
    }
    else
    {
        vector<int> ans = solve(n - 1, m - (1ll << (n - 2)));
        for (auto& x: ans) x++;
        ans.push_back(1);
        return ans;
    }
}

int main()
{
    {
        ll n, m;
        cin >> n >> m;
        vector<int> a = solve(n, m);
        for (auto x: a) printf("%d ", x);
        printf("\n");
        return 0;
    }
    
    int n = 5;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
 
    int fMax = 0;
    
    do
    {
        fMax = max(fMax, f(a));
    }
    while (next_permutation(a.begin(), a.end()));
    
    printf("max f %d\n", fMax);
    
    int cnt = 0;
    
    sort(a.begin(), a.end());
    do
    {
        if (f(a) != fMax) continue;
        
        for (auto x: a)
            printf("%d ", x);
        printf(" = %d", f(a));
        
        if (f(a) == fMax)
        {
            confirm(a);
            printf(" good");
            cnt++;
        }
        printf("\n");
    }
    while (next_permutation(a.begin(), a.end()));
    
    printf("%d\n", cnt);
    
    return 0;
}