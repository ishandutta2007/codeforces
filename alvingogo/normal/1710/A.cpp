#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        int ax=0,ay=0,zx=0,zy=0;
        for(int i=0;i<k;i++){
            int a;
            cin >> a;
            int b=a/n,c=a/m;
            if(b>2){
                zx=1;
            }
            if(c>2){
                zy=1;
            }
            if(b>=2){
                ax+=b;
            }
            if(c>=2){
                ay+=c;
            }
        }
        if((ax>=m && (m%2==0 || zx==1)) || (ay>=n && (n%2==0 || zy==1))){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}