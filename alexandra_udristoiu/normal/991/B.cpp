#include<iostream>
#include<algorithm>
using namespace std;
int n, i, sum;
int v[105];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        sum += v[i];
    }
    if(2 * sum >= 9 * n){
        cout<< 0;
        return 0;
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i <= n; i++){
        sum += 5 - v[i];
        if(2 * sum >= 9 * n){
            cout<< i;
            return 0;
        }
    }
}