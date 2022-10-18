#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base:: sync_with_stdio();
    cin.tie();
    cout.tie();
    long long n,l,a;
    cin >> n >> l >> a;
    //vector < vector < long long > > matr;
    int res = 0;
    int prx = 0, pry = 0;
    for (int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        res += (x - pry) / a;
        prx = x;
        pry = x + y;
    }
    res += (l - pry) / a;
    cout<<res<<endl;
}