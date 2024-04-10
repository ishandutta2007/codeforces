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
        int n,m,x,y,d;
        cin >> n >> m >> x >> y >> d;
        if(((x-1>d && m-y>d) || (n-x>d && y-1>d)) && (n-x+m-y>d)){
            cout << n+m-2 << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
    return 0;
}