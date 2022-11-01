#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    array<int,2> m={51,0};
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        if(a<m[0]) m={a,1};
        else if(a==m[0]) m[1]++;
    }
    if(m[1]<=n/2) cout << "Alice\n";
    else cout << "Bob\n";
    return 0;
}