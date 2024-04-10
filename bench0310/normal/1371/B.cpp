#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,r;
        cin >> n >> r;
        ll res=(min(n-1,r)*(min(n-1,r)+1)/2);
        if(max(0ll,r-n+1)>0) res++;
        cout << res << "\n";
    }
    return 0;
}