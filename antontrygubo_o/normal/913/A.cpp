#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    int t = 1;
    while (t<=m&&n) {t*=2; n--;}
    if (t>m) cout<<m;
    else cout<<m%t;
}