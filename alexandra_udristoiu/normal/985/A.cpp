#include<iostream>
#include<algorithm>
using namespace std;
int n, i, sol1, sol2;
int v[105];
int modul(int x){
    if(x >= 0){
        return x;
    }
    return -x;
}
int main(){
    cin>> n;
    n /= 2;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i < n + n; i += 2){
        sol1 += modul(v[i / 2 + 1] - i);
    }
    for(i = 2; i <= n + n; i += 2){
        sol2 += modul(v[i / 2] - i);
    }
    cout<< min(sol1, sol2);
}