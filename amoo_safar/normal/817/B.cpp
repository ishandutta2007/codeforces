#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a[100000];
ll b[100000];
ll c[100000];
int main(){
    ll n;
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    ll j,t = 0;
    for(int i =0;i<3;i++){
        t = 0;
        j = i;
        while(a[j] ==a[i]){
            t++;
            j++;
        }
        b[i]  = t;
    }
    ll out;
    if(a[0] == a[1]){
        //cout << 2;
        if(a[1]== a[2]){
            //cout << b[0];
            out = b[0]*(b[0]-1)*(b[0]-2)/6;
        }else{
            out = b[2];
        }
    }else{
        if(a[1] == a[2]){
            out = ((b[1]*(b[1]-1))/2);
        }else{
            out = b[2];
        }
    }
    cout << out;
    return 0;
}