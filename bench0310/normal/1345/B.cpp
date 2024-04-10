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
        auto c=[&](int h)->int{return (3*h*h+h)/2;};
        int h=0;
        while(c(h+1)<=n) h++;
        int res=0;
        for(;h>=1;h--)
        {
            while(c(h)<=n)
            {
                res++;
                n-=c(h);
            }
        }
        cout << res << "\n";
    }
    return 0;
}