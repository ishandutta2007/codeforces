#include<iostream>
#include<algorithm>
using namespace std;
int t, n, i, ok;
int v[200005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 0; i < n; i++){
            cin>> v[i];
            v[i] = (i + v[i]) % n;
            if(v[i] < 0){
                v[i] += n;
            }
        }
        sort(v, v + n);
        ok = 0;
        for(i = 1; i < n; i++){
            if(v[i] == v[i - 1]){
                ok = 1;
                break;
            }
        }
        if(ok == 0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}