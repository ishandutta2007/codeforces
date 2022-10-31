#include<iostream>
#include<algorithm>
using namespace std;
int n, i, ok, nr;
int v[100005];
long long sum;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    sort(v + 1, v + n + 1);
    if(n >= 2 && v[1] == v[2] && v[1] == 0){
        cout<<"cslnb";
        return 0;
    }
    for(i = 1; i < n; i++){
        if(v[i] == v[i + 1]){
            nr++;
            if(i != 1 && v[i] - 1 == v[i - 1]){
                ok = 1;
            }
        }
    }
    if(ok == 1 || nr >= 2){
        cout<<"cslnb";
        return 0;
    }
    for(i = 1; i <= n; i++){
        sum += v[i] - i + 1;
    }
    if(sum % 2 == 1){
        cout<<"sjfnb";
    }
    else{
        cout<<"cslnb";
    }
}