#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main(){
    int q,n,m,x;
    cin>>n>>m;
    ll a[105]={},b[105]={};
    cin>>x;
    for(int i = 0;i<x;i++){
        cin>>q;
        a[q] = 1;
    }
    cin>>x;
    for(int i = 0;i<x;i++){
        cin>>q;
        b[q] = 1;
    }
    int diff = __gcd(n,m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(abs(i - j)%diff == 0){
                a[i] = a[i] | b[j];
                b[j] = a[i] | b[j];
            }
        }
        for(int j = 0; j < m; j++){
            if(abs(i - j)%diff == 0){
                a[i] = a[i] | b[j];
                b[j] = a[i] | b[j];
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(abs(i - j)%diff == 0){
                b[i] = a[j] | b[i];
                a[j] = a[j] | b[i];
            }
        }
        for(int j = 0; j < n; j++){
            if(abs(i - j)%diff == 0){
                b[i] = a[j] | b[i];
                a[j] = a[j] | b[i];
            }
        }
    }
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) flag = 1;
    }            
    if(flag == 1) cout<<"No\n";
    else cout<<"Yes\n";
}