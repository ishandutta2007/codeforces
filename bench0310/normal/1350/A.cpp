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
        int n,k;
        cin >> n >> k;
        for(int i=2;i<=n;i++)
        {
            if((n%i)==0)
            {
                cout << n+i+(k-1)*2 << "\n";
                break;
            }
        }
    }
    return 0;
}