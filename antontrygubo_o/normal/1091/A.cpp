#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);

    int y, b, r;
    cin>>y>>b>>r;
    int minn = 10000;
    minn = min(y, b-1);
    minn = min(minn, r-2);
    cout<<3*minn+3;
}