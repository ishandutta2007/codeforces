#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define sz(x) ((int)x.size())
#define endl "\n"
#define inf (1LL<<62)
#define ninf (-inf)

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, dx1, dx2, dy1, dy2;
    cin >> n >> dx1 >> dy1 >> dx2 >> dy2;
    if(dx1 == dx2 && dx1 == 0)
    {
        cout << "NO\n";
        exit(0);
    }
    if(dy1 == dy2 && dy1 == 0)
    {
        cout << "NO\n";
        exit(0);
    }
    if(dx1 == dy2 && dx1 == 0)
    {
        int xr = llabs(dx2);
        int yr = llabs(dy1);
        if(xr*yr == n)
        {
            cout << "YES\n";
            for(int i = 0; i < xr; i++)
                for(int j = 0; j < yr; j++)
                    cout << i << " " << j << "\n";
        }
        else
            cout << "NO\n";
        exit(0);
    }
    if(dx2 == dy1 && dx2 == 0)
    {
        int xr = llabs(dx1);
        int yr = llabs(dy2);
        if(xr*yr == n)
        {
            cout << "YES\n";
            for(int i = 0; i < xr; i++)
                for(int j = 0; j < yr; j++)
                    cout << i << " " << j << "\n";
        }
        else
            cout << "NO\n";
        exit(0);
    }
    if(dx1*dx2 != 0)
    {
        int g = __gcd(llabs(dx1), llabs(dx2));
        int xr = g;

        int a = dx2/g, b = dx1/g;
        int yr = llabs((-1*a*dy1) + (b*dy2));
        if(xr*yr == n)
        {
            cout << "YES\n";
            for(int i = 0; i < xr; i++)
                for(int j = 0; j < yr; j++)
                    cout << i << " " << j << "\n";
            exit(0);
        }
    }
    if(dy1*dy2 != 0)
    {
        int g = __gcd(llabs(dy1), llabs(dy2));
        int yr = g;
        int a = dy2/g, b = dy1/g;
        int xr = llabs((-1*a*dx1) + (b*dx2));
        if(xr*yr == n)
        {
            cout << "YES\n";
            for(int i = 0; i < xr; i++)
                for(int j = 0; j < yr; j++)
                    cout << i << " " << j << "\n";
            exit(0);
        }
    }
    cout << "NO\n";
}