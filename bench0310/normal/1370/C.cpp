#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool solve(int n)
{
    if(n==1) return 0;
    if(n==2||(n&1)) return 1;
    for(int i=2;i*i<=n;i++)
    {
        if((n%i)>0) continue;
        if((i&1)&&solve(n/i)==0) return 1;
        if(((n/i)&1)&&solve(i)==0) return 1;
    }
    return 0;
}

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
        if(solve(n)==1) cout << "Ashishgup\n";
        else cout << "FastestFinger\n";
    }
    return 0;
}