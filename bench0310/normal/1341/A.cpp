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
        int n,a,b,c,d;
        cin >> n >> a >> b >> c >> d;
        int al=n*(a-b);
        int ar=n*(a+b);
        int bl=c-d;
        int br=c+d;
        if(max(al,bl)<=min(ar,br)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}