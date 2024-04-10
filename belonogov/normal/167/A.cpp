#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long double ld;
#define forn(i, n) for(i = 0; i < n; i++)

int main(){
    ld tpred = 0, t2, t1, a, d, ts, v;
    int i, n;
    cin >> n >> a >> d;
    cout.precision(15);
    forn(i, n){
        cin >> ts >> v;
        t1 = (v * 1.0) / a;  
        if (t1 * t1 * a / 2 >= d){
            t2 = sqrt(2.0 * d / a) + ts;
            t2 = max(tpred, t2);
            tpred = t2;
            cout << fixed << t2 << "\n"; 
        }
        else{
            t2 = (v * 1.0) / a;
            t2 += (d - t2 * t2 * a / 2) / v + ts;
            t2 = max(tpred, t2);
            tpred = t2;
            cout << fixed << t2 << "\n"; 
        }
    }

    return 0;
}