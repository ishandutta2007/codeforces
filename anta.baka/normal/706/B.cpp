#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int,int>
#define ff first
#define ss second
 
const int N = 1e5;
int x[N], ans[N];
pii y[N];
 
int main()
{
    int n, q;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    cin >> q;
    for(int i = 0; i < q; i++)
        cin >> y[i].ff, y[i].ss = i;
    sort(x, x + n);
    sort(y, y + q);
    int p = -1;
    for(int i = 0; i < q; i++) {
        while(p + 1 < n && y[i].ff >= x[p + 1])
            p++;
        ans[y[i].ss] = p + 1;
    }
    for(int i = 0; i < q; i++, cout << "\n")
        cout << ans[i];
    return 0;
}