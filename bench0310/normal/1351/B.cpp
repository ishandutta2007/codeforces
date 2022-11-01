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
        int a,b;
        cin >> a >> b;
        if(a>b) swap(a,b);
        int c,d;
        cin >> c >> d;
        if(c>d) swap(c,d);
        if(a+c==b&&b==d) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}