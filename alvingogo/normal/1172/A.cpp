#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;
 
int main(){
    AquA;
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int j=0;j<n;j++){
        cin >> b[j];
    }
    int nw=0;
    for(int i=0;i<n;i++){
        if(b[i]!=0){
            nw=max(nw,i-b[i]+2);
        }
    }
    vector<int> vis(n);
    for(int i=0;i<n;i++){
        if(a[i]){
            vis[a[i]-1]=1;
        }
    }
    int z=-1;
    for(int i=0;i<n;i++){
        if(b[i]==1){
            z=i;
            break;
        }
    }
    int flag=0;
    for(int i=z;i<n;i++){
        if(b[i]!=i-z+1){
            flag=1;
        }
        else{
            if(b[i]){
                vis[b[i]-1]=1;
            }
        }
    }
    if(flag==0){
        for(int u=0;u<z;u++){
            if(!vis[b[n-1]+u]){
                flag=1;
                break;
            }
            if(b[u]){
                vis[b[u]-1]=1;
            }
        }
    }
    if(flag==0){
        cout << z << "\n";
        return 0;
    }
    cout << nw+n << "\n";
    return 0;
}