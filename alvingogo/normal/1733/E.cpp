#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;
 
int main(){
    AquA;
    int q;
    cin >> q;
    while(q--){
        long long t,x,y;
        cin >> t >> x >> y;
        if(t<x+y){
            cout << "NO\n";
            continue;
        }
        t-=x+y;
        t++;
        vector<vector<long long> > v(120,vector<long long>(120));
        v[0][0]=t;
        for(int i=0;i<120;i++){
            for(int j=0;j<120;j++){
                if(i){
                    v[i][j]+=v[i-1][j]/2;
                }
                if(j){
                    v[i][j]+=v[i][j-1]/2;
                    v[i][j]+=v[i][j-1]%2;
                }
            }
        }
        int nx=0,ny=0;
        for(;nx+ny<x+y && nx<120 && ny<120;){
            if(v[nx][ny]%2){
                ny++;
            }
            else{
                nx++;
            }
        }
        if(nx==x && ny==y){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}