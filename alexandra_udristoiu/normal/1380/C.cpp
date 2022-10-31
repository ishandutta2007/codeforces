#include<iostream>
#include<algorithm>
using namespace std;
int n, t, i, nr, pos, x;
int v[100005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> x;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        sort(v + 1, v + n + 1);
        pos = n + 1;
        nr = 0;
        for(i = n; i >= 1; i--){
            if(v[i] * 1LL * (pos - i) >= x){
                nr++;
                pos = i;
            }
        }
        cout<< nr <<"\n";
    }
}