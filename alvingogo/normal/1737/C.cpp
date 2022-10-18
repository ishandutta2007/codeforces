#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;


int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[6]={0};
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
        int cnt=0;
        for(int i=0;i<6;i++){
            if(a[i]==n || a[i]==1){
                cnt++;
            }
        }
        int x,y;
        cin >> x >> y;
        if(cnt>=4){
            int u=0,v=0;
            for(int i=0;i<6;i+=2){
                if(a[i]==n || a[i]==1){
                    u=a[i];
                }
                if(a[i+1]==n || a[i+1]==1){
                    v=a[i+1];
                }
            }
            if(x!=u && y!=v){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
        else{
            pair<int,int> b={x%2,y%2};
            if(b!=pair<int,int>(a[0]%2,a[1]%2) && b!=pair<int,int>(a[2]%2,a[3]%2) && b!=pair<int,int>(a[4]%2,a[5]%2)){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
    }
    return 0;
}