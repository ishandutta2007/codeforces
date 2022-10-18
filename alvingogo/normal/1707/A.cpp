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
        int n,q;
        cin >> n >> q;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        vector<int> s(n);
        for(int i=0;i<n;i++){
            if(q>=v[i]){
                s[i]=1;
            }
        }
        int l=0,r=n-1;
        while(r>l){
            int m=(l+r)/2;
            int flag=0,z=q;
            for(int i=0;i<n;i++){
                if(z<=0){
                    flag=1;
                    break;
                }
                if(z>=v[i]){
                    
                }
                else{
                    if(m<=i){
                        z--;
                    }
                }
            }
            if(flag){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        for(int i=0;i<n;i++){
            if(q>=v[i]){
                cout << "1";
            }
            else if(l<=i){
                cout << "1";
            }
            else{
                cout << "0";
            }
        }
        cout << "\n";
    }
    
    return 0;
}