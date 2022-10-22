#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

li xarea(int a, int b, int c, int d)
{
    return max(0, min(b, d) - max(a, c));
}

li area(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    return xarea(x1, x2, x3, x4) * (li)xarea(y1, y2, y3, y4);
}

bool can(int a, int b, int x1, int y1, int x2, int y2)
{
    for (int t1 = 0; t1 < 2; t1++)
    {
        for (int t2 = 0; t2 < 2; t2++)
        {
            //printf("%d %d, %d %d, %d %d\n", a, b, x1, y1, x2, y2);
            if (!(x1 > a || y1 > b || x2 > a || y2 > b))
            {
                if (area(0, 0, x1, y1, a - x2, b - y2, a, b) == 0)
                    return true;
            }
            
            swap(x2, y2);
        }
        swap(x1, y1);
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    
    li answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (can(a, b, x[i], y[i], x[j], y[j]))
            {
                answer = max(answer, x[i] * (li)y[i] + x[j] * (li)y[j]);
            }
            
    cout << answer << endl;
    
    return 0;
}