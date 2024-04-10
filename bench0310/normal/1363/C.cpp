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
        int n,x;
        cin >> n >> x;
        int d=0;
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            d+=(a==x||b==x);
        }
        if(d<=1||((n-1)&1)) cout << "Ayush\n";
        else cout << "Ashish\n";
    }
    return 0;
}