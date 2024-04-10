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
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int r=0;
        long long ans=0;
        for(int i=0;i<n-1;i++){
            if(v[i]==0){
                continue;
            }
            else{
                int flag=0;
                while(v[i]){
                    while(r<i){
                        r++;
                    }
                    while(r<n && v[r]>0){
                        r++;
                    }
                    if(r==n){
                        for(int j=i;j<n-1;j++){
                            ans+=v[j];
                        }
                        flag=1;
                        break;
                    }
                    else{
                        v[i]--;
                        v[r]++;
                        ans++;
                    }
                }
                if(flag){
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}