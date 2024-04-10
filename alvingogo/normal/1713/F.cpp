#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n;
    cin >> n;
    int m=1,cnt=1;
    while(m<n){
        m<<=1;
        cnt++;
    }
    vector<int> v(m),b(m);
    for(int i=0;i<n;i++){
        cin >> v[i];
        b[i]=v[i];
    }
    for(int i=0;i<cnt;i++){
        for(int j=0;j<m;j++){
            if((j>>i)&1){
                v[j]^=v[j^(1<<i)];
            }
        }
    }
    for(int i=0;i<cnt;i++){
        for(int j=n;j<m;j++){
            if((j>>i)&1){
                if((j^(1<<i))>=n){
                    v[j]^=v[j^(1<<i)];
                }
            }
        }
    }
    for(int i=0;i<m/2;i++){
        swap(v[i],v[m-1-i]);
    }
    for(int i=m-n;i<m;i++){
        v[i]=b[m-i-1];
    }
    for(int i=0;i<cnt;i++){
        for(int j=0;j<m;j++){
            if((j>>i)&1){
                v[j]^=v[j^(1<<i)];
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << v[n-i-1] << " ";
    }
    cout << "\n";
    return 0;
}