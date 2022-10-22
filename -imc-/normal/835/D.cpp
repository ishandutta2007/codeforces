#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

vector<int> z_func(string s)
{
    int n = s.length();
    
    vector<int> z(n);
    z[0] = n;
    
    int l = 0, r = -1;
    for (int i = 1; i < n; i++)
    {
        z[i] = max(min(z[i - l], r - i + 1), 0);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int n = s.length();
    
    vector<vector<int>> d(n, vector<int>(n));
    
    for (int l = n - 1; l >= 0; l--)
    {
        string g = s.substr(l);
        string grev = g;
        reverse(all(grev));
        vector<int> z = z_func(g + grev);
        
        //printf("%s -> ", g.c_str()); for (int c: z) printf("%d ", c); printf("\n");
        
        for (int r = l; r < n; r++)
        {
            if (l == r) { d[l][r] = 1; continue; }
            
            int half = (r - l + 1) / 2;
            if (z[r - half + 1 - l] >= half)
            {
                //printf("ok read %d %d\n", l, r);
                d[l][r] = min(d[l][l + half - 1], d[r - half + 1][r]) + 1;
                if (d[l][r] == 1) d[l][r] = 0;
            }
            
            if (z[(int)z.size() - (r - l + 1)] == (r - l + 1))
                d[l][r] = max(d[l][r], 1);
        }
    }
    
#if 0
    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++)
            printf("d %d %d is %d\n", l + 1, r + 1, d[l][r]);
#endif
    
    vector<int> ans(n + 1);
    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++)
            ans[d[l][r]]++;
        
    for (int i = n - 1; i >= 0; i--)
        ans[i] += ans[i + 1];
        
    for (int i = 0; i < n; i++)
        cout << ans[i + 1] << ' ';
    cout << "\n";
    
    return 0;
}