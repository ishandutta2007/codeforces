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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        bool inc=1;
        for(int i=0;i<n-1;i++) inc&=(a[i]<=a[i+1]);
        bool x=0;
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> b[i];
        for(int i=0;i<n-1;i++) x|=(b[i]!=b[i+1]);
        if(inc||x) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}