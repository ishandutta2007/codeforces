#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);

    ll result = 0;
    string s;
    int n;
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        cin>>s;
        if (s=="Tetrahedron") result+=4;
        if (s=="Cube") result+=6;
        if (s=="Octahedron") result+=8;
        if (s=="Dodecahedron") result+=12;
        if (s=="Icosahedron") result+=20;
    }
    cout<<result;
}