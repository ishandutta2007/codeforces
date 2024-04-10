#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long li;

vector<int> prefixFunction(string s)
{
    int n = s.length();
    
    vector<int> p(n);
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i - 1];
        while (s[p[i]] != s[i] && p[i] != 0)
            p[i] = p[p[i] - 1];
        if (s[p[i]] == s[i])
            p[i]++;
    }
    return p;
}

int main()
{
#if 0
    string k = "abacabadabacaba";
    vector<int> v = prefixFunction(k);
    for (int x: v) cout << x << " ";
    cout << endl;
    return 0;
#endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> numLength(8001);
    for (int i = 0; i < (int)numLength.size(); i++)
    {
        int x = i;
        while (x)
        {
            x /= 10;
            numLength[i]++;
        }
    }
    
    string s;
    
    if (true)
        cin >> s;
    else
    {
        for (int i = 0; i < 8000; i++) s += "abc"[rand() % 2];
    }
    int n = s.length();
    
    vector<int> ans(n + 1, (int)1e9);
    ans[0] = 0;
    
    for (int i = 0; i < n; i++)
    {
        string t = s.substr(0, i + 1);
        reverse(all(t));
        vector<int> p = prefixFunction(t);
        
        //if (i % 1000 == 0) printf("%d\n", i);
        
        for (int j = 0; j <= i; j++)
        {
            // use ans[j]
            int period = (i - j + 1) - p[i - j];
            //printf("period %d\n", period);
            
            if ((i - j + 1) % period != 0)
                period = i - j + 1;
            int numReps = (i - j + 1) / period;
            
            ans[i + 1] = min(ans[i + 1], ans[j] + numLength[numReps] + period);
        }
    }
    
    cout << ans[n] << endl;
    
    return 0;
}