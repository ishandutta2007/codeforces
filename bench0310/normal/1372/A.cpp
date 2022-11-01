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
        int n;
        cin >> n;
        if(n==2) cout << "1 3\n";
        else for(int i=1;i<=n;i++) cout << (i<n?1:n) << " \n"[i==n];
    }
    return 0;
}