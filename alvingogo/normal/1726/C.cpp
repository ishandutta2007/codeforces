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
        string s;
        cin >> s;
        int ans=n;
        for(int i=0;i<2*n-1;i++){
            if(s[i]==')' && s[i+1]=='('){
                ans--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}