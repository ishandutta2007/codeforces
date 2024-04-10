#include<iostream>
using namespace std;
int n, i, st, dr;
int v[105];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    st = 1;
    while(st < n && v[st] < v[st + 1]){
        st++;
    }
    dr = n;
    while(dr > 1 && v[dr] < v[dr - 1]){
        dr--;
    }
    for(i = st + 1; i <= dr; i++){
        if(v[i] != v[i - 1]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}