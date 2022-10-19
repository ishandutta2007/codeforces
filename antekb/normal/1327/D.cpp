#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int> V[N];
int P[N], c[N];
bool vis[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>P[i];
        }
        for(int i=1; i<=n; i++){
            cin>>c[i];
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                V[cnt].push_back(i);
                for(int k=P[i]; k!=i; k=P[k]){
                    V[cnt].push_back(k);
                    vis[k]=1;
                }
                cnt++;
            }
        }
        //cout<<cnt<<" ";
        int ans=N;
        for(int l=0; l<cnt; l++){
            int m=V[l].size();
            //for(int i)
            vector<int> Q;
            int k;
            for(k=1; k*k<m; k++){
                if(m%k==0){
                    Q.push_back(k);
                    Q.push_back(m/k);
                }
            }
            if(k*k==m){
                Q.push_back(k);
            }
            sort(Q.begin(), Q.end());
            //reverse(Q.begin(), Q.end());
            for(int i:Q){
                //cout<<"\n"<<i<<"b"<<ans<<"\n";
                for(int j=0; j<i; j++){
                    if(i>ans)   break;
                    bool b=1;
                    for(k=1; k<m/i; k++){
                        if(c[V[l][j+(k-1)*i]]!=c[V[l][j+k*i]]){
                            b=0;
                            break;
                        }
                    }
                    if(b)   ans=i;
                }
            }
        }
        cout<<ans<<"\n";
        for(int i=0; i<cnt; i++){
            V[i].clear();
        }
        for(int i=1; i<=n; i++){
            vis[i]=0;
        }
    }
}