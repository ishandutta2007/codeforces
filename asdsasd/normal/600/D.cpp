#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<atcoder/lazysegtree>
using namespace std;
//using namespace atcoder;

void solve(){
    long double x1, x2, y1, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    long double pi = acos(-1);
    if(r1 > r2){
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    long double dx = x2 - x1;
    long double dy = y2 - y1;
    long double d2 = dx * dx + dy * dy;
    cout << fixed << setprecision(12);
    if(d2 <= (r1 - r2) * (r1 - r2)){
        cout << pi * r1 * r1 << "\n";
    }
    else if(d2 >= (r1 + r2) * (r1 + r2)){
        cout << 0 << "\n";
    }
    else{
        long double d = sqrt(d2);
        long double x1 = ((r1 * r1 - r2 * r2 + d2) / (2 * d));
        long double x2 = d - x1;
        long double h = sqrt(r1 * r1 - x1 * x1);
        long double s = r1 * r1 * atan2(h, x1);
        s += r2 * r2 * atan2(h, x2);
        s -= h * d;
        cout << s << "\n";
    }
    

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--) solve();
}