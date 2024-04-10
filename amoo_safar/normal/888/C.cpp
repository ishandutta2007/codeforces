#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000];
int b[603];
int main(){
    string a,b="abcdefghigklmnopqrstuvwxyz";
    cin >> a;
    char c;
    ll t =0,ma;
    ll k = 1000001;
    for(int i =0;i<26;i++){
        c = b[i];
        ma = 0;
        t=0;
        for(int j =0;j<a.size();j++){
            if(a[j] == c){
                ma = max(ma,t);
                t=0;
            } else {
                t++;
            }
        }
        ma = max(ma,t);
        k = min(k,ma);
    }
    cout << k+1;
    return 0;
}