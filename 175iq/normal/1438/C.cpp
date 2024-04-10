#include <bits/stdc++.h>
using namespace std;
 
int t = 1;
 
int n, m;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i++, cout << "\n")
            for(int j = 1; j <= m; j++)
            {
                int a;
                cin >> a;
                if(a % 2 != (i + j) % 2)
                    a++;
                cout << a << " ";
            }
    }
    return 0;
}