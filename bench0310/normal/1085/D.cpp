#include <bits/stdc++.h>

using namespace std;

int a,b,n,g[100001],c,i;
double s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(i=0;i<n-1;i++)
    {
        cin >> a >> b;
        g[a]++; g[b]++;
    }
    for(i=1;i<=n;i++) if(g[i]==1) c++;
    cout << fixed << setprecision(14) << s/c*2.0 << endl;
    return 0;
}