#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200000+5;
const int MOD=998244353;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int y, b, r;
    cin >> y >> b >> r;
    int res=0;
    if (y+1<=b && y+2<=r) res=y+(y+1)+y+2;
    else if (b-1<=y && b+1<=r) res=3*b;
    else if (r-2<=y && r-1<=b) res=3*r-3;
    cout << res;
    return 0;
}