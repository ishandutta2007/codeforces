#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

li c[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
#if 0
    c[1][0] = c[1][1] = 1;
    for (int n = 2; n < 100; n++)
    {
        for (int k = 0; k <= n; k++)
        {
            if (k == 0) { c[n][k] = 1; continue; }
            c[n][k] = c[n - 1][k] + c[n - 1][k - 1];
        }
    }
    
#if 0
    for (int n = 1; n < 5; n++)
    {
        for (int k = 0; k <= n; k++)
        {
            printf("%d ", c[n][k]);
        }
        printf("\n");
    }
#endif
    
    int n = 5;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = 1;
    
    for (int i = 0; i < 10; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << ", exp: ";
        for (int j = 0; j < n; j++)
            cout << c[i + j][j] << " ";
        cout << "\n";
        
        for (int j = 1; j < n; j++)
            a[j] += a[j - 1];
    }
#endif

    int n;
    li k;
    cin >> n >> k;
    
    vector<li> a(n);
    int first = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0 && first == -1)
            first = i;
        
        if (a[i] >= k)
        {
            cout << "0\n";
            return 0;
        }
    }
    
    {
        vector<li> b;
        copy(a.begin() + first, a.end(), back_inserter(b));
        a = b;
    }
    
    n = a.size();
    
    if (n >= 4)
    {
        // growth is at least cubic
        
        int answer = 0;
        while (true)
        {
            answer++;
            for (int i = 1; i < n; i++)
            {
                a[i] += a[i - 1];
                
                if (a[i] >= k)
                {
                    goto breakAll;
                }
            }
        }
        
        breakAll:;
        cout << answer << endl;
    }
    else if (n >= 3)
    {
        li low = 0, high = 2e9;
        
        while (low + 1 != high)
        {
            li m = (low + high) / 2;
            
            long double sumld = a[0] * (long double)((m + 1) * (long double)m / 2) + a[1] * m + a[2];
            if (sumld / k >= 2)
            {
                high = m;
                continue;
            }
            
            li sum = a[0] * ((m + 1) * m / 2) + a[1] * m + a[2];
            if (sum >= k)
                high = m;
            else
                low = m;
        }
        
        cout << high << endl;
    }
    else
    {
        li answer = (k - a[1] + a[0] - 1) / a[0];
        cout << answer << endl;
    }
    
    return 0;
}