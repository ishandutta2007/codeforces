#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> V;
        V.resize(n);
        for(int i=0; i<n; i++){
            cin>>V[i];
        }
        sort(V.begin(), V.end());
        int ans=0;
        for(int i=1; i<n; i++){
            if(V[i]!=V[i-1]){
                ans++;
            }
        }
        cout<<ans+1<<"\n";
    }
}