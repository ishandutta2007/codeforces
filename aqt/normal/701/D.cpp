#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
double L, V1, V2, K;

bool check(double lim){
    int remain = N;
    double X1 = 0;

    while(true){
        if(lim <= 0){
            return false;
        }

        double D = L - X1;

        //R / V2 + (D - R) / V1 = lim
        //R * V1 + (D - R) * V2 = lim * V1 * V2
        //R * (V1 - V2) + D * V2 = lim * V1 * V2
        //R = (lim * V1 * V2 - D * V2) / (V1 - V2)

        double R = (lim * V1 * V2 - D * V2) / (V1 - V2);
        R = max(R, 0.0);

        if(R > D){
            return false;
        }

        remain -= K;
        if(remain <= 0){
            return true;
        }

        double X2 = X1 + R;
        X1 += (R / V2) * V1;

        lim -= R / V2;

        double diff = X2 - X1;
        lim -= diff / (V1 + V2);
        
        X1 += diff * V1 / (V1 + V2);
    }

    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> L >> V1 >> V2 >> K;

    double lo = 0, hi = 1e9;
    for(int a = 0; a < 100; a++){
        double mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(9) << lo;
}