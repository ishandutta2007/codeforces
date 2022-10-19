#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef pair<int, int> pii;
const int K=300, N=1e5+5;
int f[N], tim[N], gdzie[N];
int n;
int update(int k){
    for(int i=min(n-1, (k+1)*K-1); i>=K*k; i--){
        if(f[i]>=K*(k+1) || f[i]>=n){
            tim[i]=1;
            gdzie[i]=i;
        }
        else{
            tim[i]=tim[f[i]]+1;
            gdzie[i]=gdzie[f[i]];
        }
    }
}
pii Find(int x){
    int t=0;
    while(f[x]<n){
        //cout<<x<<"a";
        t+=tim[f[x]];
        x=gdzie[f[x]];
    }
    return {x, t};
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>f[i];
        f[i]+=i;
    }
    for(int i=0; i<=n/K; i++){
        update(i);
    }
    while(q--){
        int t, x, y;
        cin>>t;
        if(t==0){
            cin>>x>>y;
            x--;
            f[x]=x+y;
            update(x/K);
        }
        else{
            cin>>x;
            x--;
            pii a=Find(x);
            cout<<a.st+1<<" "<<a.nd+1<<"\n";
        }
        /*for(int i=0; i<n; i++){
            cout<<i<<" "<<f[i]<<" "<<tim[i]<<" "<<gdzie[i]<<"\n";
        }
        cout<<"\n";*/
    }
}