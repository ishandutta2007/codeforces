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
        if(a==b) cout << "0";
        else if(a<b) cout << 2-((b-a)&1);
        else cout << 1+((a-b)&1);
        cout << "\n";
    }
    return 0;
}