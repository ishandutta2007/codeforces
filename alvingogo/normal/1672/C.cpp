#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int cnt=0;
        int minx=1e9,maxx=0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(i){
                if(v[i]==v[i-1]){
                    cnt++;
                    minx=min(minx,i);
                    maxx=max(maxx,i);
                }
                
            }
        }
        if(cnt<=1){
            cout << 0 << "\n";
        }
        else{
            cout << max(1,maxx-minx-1) << "\n";
        }
    }
	return 0;
}