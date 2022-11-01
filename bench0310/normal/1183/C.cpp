#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        ll k,n,a,b;
        cin >> k >> n >> a >> b;
        if(n*b<k) cout << min(n,(k-n*b-1)/(a-b)) << "\n";
        else cout << "-1\n";
    }
    return 0;
}