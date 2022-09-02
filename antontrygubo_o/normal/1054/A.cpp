#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;


int main()
{
   ios_base::sync_with_stdio(0);
    int x, y, z, t1, t2, t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    int res1 = abs(x-y)*t1;
    int res2 = abs(x-z)*t2 + abs(x-y)*t2+3*t3;

    if (res1<res2) cout<<"NO"; else cout<<"YES";
    
}