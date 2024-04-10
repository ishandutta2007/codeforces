#include <bits/stdc++.h>

using namespace std;

int main(){
    double N, R;
    double PI = 3.14159265358979323846;
    cin >> N >> R;
    double ep = 0.00000000001;
    double l = 0, r = 1000;
    double chk = 1-cos(2*PI/N);
    while(r - l > ep){
        double mid = (l+r)/2;
        if(2*mid*mid/((mid+R)*(mid+R)) - chk > ep){
            r = mid - ep;
        }
        else if(2*mid*mid/((mid+R)*(mid+R)) - chk < -ep){
            l = mid + ep;
        }
        else{
            printf("%.7f", mid);
            return 0;
        }
    }
    printf("%.7f", l);
}