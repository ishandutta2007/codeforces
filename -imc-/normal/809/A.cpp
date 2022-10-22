#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

const int MOD = 1e9 + 7;

typedef long long li;

int main()
{
    
    int n;
    cin >> n;
    
    vector<int> twoPower(n + 1);
    twoPower[0] = 1;
    for (int i = 1; i < (int)twoPower.size(); i++)
        twoPower[i] = twoPower[i - 1] * 2 % MOD;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(all(a));
    
    li answer = 0;
    for (int l = 0; l < n;)
    {
        int r = l;
        while (r + 1 < n && a[r + 1] == a[l]) r++;
        
        if (r + 1 >= n) break;
        
        int diff = a[r + 1] - a[l];
        int cnt_a = r + 1;
        int cnt_b = n - cnt_a;
        
        //printf("diff %d counts %d %d\n", diff, cnt_a, cnt_b);
        
        answer = (answer + (twoPower[n] - twoPower[cnt_a] - (li)twoPower[cnt_b] + 1 + 2 * (li)MOD) % MOD * (li)diff) % MOD;
        
        l = r + 1;
    }
    
    cout << answer << endl;
    
    return 0;
}