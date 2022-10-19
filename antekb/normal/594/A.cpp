#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    vector<int> V;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        V.push_back(x);
    }
    sort(V.begin(), V.end());
    int m=1e9, k=n/2;
    for(int i=0; i<k; i++){
        //cout<<V[i+k]<<" "<<V[i]<<"\n";
        m=min(m, V[i+k]-V[i]);
    }
    cout<<m;
}