#include<iostream>
#include<algorithm>
using namespace std;
int n, h, i, k, sum;
int v[1005], w[1005];
int main(){
    cin>> n >> h;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(k = 1; k <= n; k++){
        for(i = 1; i <= k; i++){
            w[i] = v[i];
        }
        sort(w + 1, w + k + 1);
        sum = 0;
        for(i = k; i >= 1; i -= 2){
            sum += w[i];
            if(sum > h){
                break;
            }
        }
        if(sum > h){
            break;
        }
    }
    cout<< k - 1;
}