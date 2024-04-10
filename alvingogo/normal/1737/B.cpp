#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

long long cnt(long long x){
    if(x==0){
        return 0;
    }
    int l=1,r=1e9+7;
    while(r>l){
        int m=(l+r+1)/2;
        if(1ll*m*m<=x){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    int m=l;
    long long cnt=3ll*m-2;
    if(1ll*m*m+m<=x){
        cnt++;
    }
    if(1ll*m*m+m+m<=x){
        cnt++;
    }
    return cnt;
}
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        long long l,r;
        cin >> l >> r;
        l--;
        cout << cnt(r)-cnt(l) << "\n";
    }
    return 0;
}