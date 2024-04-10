#include <bits/stdc++.h>
using namespace std;
static int n, k, l, v1, v2, a;
bool achieve(double x){
    double good = (a-1)*2*x*v1/(v1 + v2) + x;
    if(good<= l){
        return true;
    }
    return false;
}
int main(){
    cin >> n >> l >> v1 >> v2 >> k;
    a = ceil(((double) n)/k);
    double lo = 0;
    double hi = l;
    while(abs(hi - lo) >= .00000001){
        double m = (lo + hi)/2;
        if(achieve(m)){
            lo = m;
        }
        else{
            hi = m;
        }
    }
    //cout << hi<< endl;
    double time = hi/v2 + (l-hi)/v1;
    cout <<setprecision(100)<< time << endl;
    return 0;
}