#include <bits/stdc++.h>
using namespace std;
long long n, m, q, sx, sy, ex, ey;
int main()
{
    long long ans1, ans2;
    cin >> n;
    cin >> m >> q;
    long long k=__gcd(n, m);
    n=n/k, m=m/k;
    for(int i=0;i<q;i++)
    {
        cin >> sx >> sy >> ex >> ey;
        if(sx==1)
        {
            ans1=(sy-1)/n;
        }
        else
            ans1=(sy-1)/m;
        if(ex==1)
            ans2=(ey-1)/n;
        else
            ans2=(ey-1)/m;
        if(ans1==ans2)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}