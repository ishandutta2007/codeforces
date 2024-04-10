#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// int dx[4] = {-1, 1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int i;
    for(i=0; i<n; i++)
        cin >> a[i];
    int ans = 0;
    int x = a[n-1];
    for(i=n-2; i>=0; i--)
    {
        if(a[i] > x)
        {
            ans++;
            x = a[i];
        }
    }
    cout << ans << endl;
}

int main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}