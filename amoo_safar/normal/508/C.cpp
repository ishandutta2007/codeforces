#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300];
int b[603];
int main(){
    ll m,t,r,r2;
    cin >> m >> t >> r;
    if(t<r){
        cout << -1;
        return 0;
    }
    for(int i =0 ;i<m;i++) cin >> a[i];
    for(int i =0 ;i<m;i++){
        r2 = r;
        for(int j = a[i]-t;j<a[i];j++){
            if(b[j+300] != 0){
                r2--;
            }
        }
        for(int j =a[i]-r2;j<a[i];j++) b[j+300] = 1;
    }
    ll tt = 0;
    for(int i =0;i<603;i++){
        if(b[i]!=0)tt++;
    }
    cout << tt;
    return 0;
}