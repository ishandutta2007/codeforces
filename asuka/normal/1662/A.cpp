#include<iostream>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
using namespace std;

int mx[20];

int main(){
    int T; cin>>T;
    while(T--){
        rep(i,1,10) mx[i] = -1;
        int n; cin>>n;
        int b, d;
        rep(i,1,n) cin>>b>>d, mx[d] = max(mx[d], b);
        int ans = 0;
        rep(i,1,10){
            if(mx[i] > 0) ans += mx[i];
            else{ ans = -1; break; }
        }
        if(ans == -1) cout<< "MOREPROBLEMS\n";
        else cout<<ans<<endl;
    }
    return 0;
}