#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
double eps = 1e-11;

double calc(double val){
    double ans = 0, pos = 0, neg = 0;
    for(int i = 1; i<=N; i++){
        pos += arr[i] - val;
        neg += arr[i] - val;
        if(pos < 0){
            pos = 0;
        }
        if(neg > 0){
            neg = 0;
        }
        ans = max(ans, max(-neg, pos));
    }
    return ans;
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    double l = -20000, r = 20000;
    while(r-l > eps){
        double mid1 = l + (r - l)/3;
        double mid2 = r - (r - l)/3;
        if(calc(mid1) < calc(mid2)){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }
    double ans = calc((l+r)/2);
    printf("%.7f\n", ans);
}