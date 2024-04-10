#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int a[N], dp[N][3];
bool sp[N], co[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1 || a[i] == 3)
            co[i] = true;
        else
            co[i] = false;
        if(a[i] == 2 || a[i] == 3)
            sp[i] = true;
        else
            sp[i] = false;
    }
    dp[0][0] = 1;
    for(int i = 1; i < n; i++)
        for(int p = 0; p < 3; p++) {
            dp[i][p] = 1000000000;
            if(!p || (p==1 && co[i]) || (p==2 && sp[i]))
                for(int q = 0; q < 3; q++)
                    if(!q || (q==1 && co[i-1]) || (q==2 && sp[i-1]))
                        if(!p || p!=q)
                            dp[i][p] = min(dp[i][p], dp[i-1][q] + (p==0));
        }
    int d1 = dp[n-1][0];
    int d2 = co[n-1] ? dp[n-1][1] : 1000000000;
    int d3 = sp[n-1] ? dp[n-1][2] : 1000000000;
    cout << min(d1, min(d2, d3));
    return 0;
}