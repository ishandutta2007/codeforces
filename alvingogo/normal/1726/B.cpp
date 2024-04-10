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
        int m;
        cin >> m;
        if(n%2==0 && m%2==1){
            cout << "NO\n";
            continue;
        }
        vector<int> v(n);
        for(int i=0;i<n-2+n%2;i++){
            v[i]=1;
            m--;
        }
        if(m<=0){
            cout << "NO\n";
            continue; 
        }
        if(n%2==0){
            v[n-1]=v[n-2]=m/2;
        }
        else{
            v[n-1]=m;
        }
        cout << "YES\n";
        for(auto h:v){
            cout << h << " ";
        }
        cout << "\n";
    }
    return 0;
}