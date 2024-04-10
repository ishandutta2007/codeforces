#include<iostream>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
using namespace std;

int main(){
    int T; cin>>T;
    while(T--){
        int n, m, r, w;
        cin>>n>>m;
        int rmx = 0, wmx = 0;
        rep(i,1,m){
            cin>>r>>w;
            rmx = max(rmx, r), wmx = max(wmx, w);
        }
        if(rmx + wmx > n){ cout<<"IMPOSSIBLE\n"; continue; }
        rep(i,1,rmx) cout<<"R";
        rep(i,1,wmx) cout<<"W";
        rep(i,1,n-rmx-wmx) cout<<"W";
        cout<<endl;
    }
    return 0;
}