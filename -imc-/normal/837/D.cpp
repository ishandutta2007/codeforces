#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void relax(int& what, int with)
{
    what = max(what, with);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n), y(n);
    
    for (int i = 0; i < n; i++)
    {
        li a;
        cin >> a;
        
        while (a % 5 == 0) { x[i]++; a /= 5; }
        while (a % 2 == 0) { y[i]++; a /= 2; }
        
        //printf("%d %d\n", x[i], y[i]);
    }
    
    const int maxN = 205;
    static int d[maxN][26 * maxN];
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        //memset(d[(i + 1) % 2], 0, sizeof(d[0]));
        
        for (int taken = k - 1; taken >= 0; taken--)
            for (int p2 = 0; p2 + y[i] < 26 * (n + 2); p2++)
                if (d[taken][p2] >= 0)
                    relax(d[taken + 1][p2 + x[i]], d[taken][p2] + y[i]);
            
        for (int p2 = 0; p2 < 26 * maxN; p2++)
        {
            //if (d[k][p2] >= 0)
            //    printf("i %d p2 %d can %d\n", i, p2, d[k][p2]);
            answer = max(answer, min(p2, d[k][p2]));
        }
    }
    
    cout << answer << endl;
    
    return 0;
}