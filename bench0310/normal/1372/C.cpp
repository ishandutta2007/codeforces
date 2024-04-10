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
        int l=0,r=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            if(a!=i)
            {
                cnt++;
                if(l==0) l=i;
                r=i;
            }
        }
        int res=2;
        if(cnt==0) res=0;
        else if(r-l+1==cnt) res=1;
        cout << res << "\n";
    }
    return 0;
}