#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef pair<int, int> pii;
const int N=1e6+5;
int sito[N], d[N];
vector<int> pierwsze;
vector<int> E[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=2; i<N; i++){
        if(sito[i]==0){
            sito[i]=i;
            if(i<1000){
                pierwsze.push_back(i);
            }
            for(int j=i; j<=(N-1)/i; j++){
                sito[i*j]=i;
            }
        }
    }
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x==1){
            cout<<1;
            return 0;
        }
        int a=sito[x], cnt=0;
        while(!(x%a)){
            cnt^=1;
            x/=a;
        }
        int b=sito[x];
        if(b==0){
            if(cnt==0){
                cout<<"1\n";
                return 0;
            }
            else{
                E[0].push_back(a);
                E[a].push_back(0);
                continue;
            }
        }
        if(cnt==0){
            E[0].push_back(b);
            E[b].push_back(0);
        }
        else{
            if(!((x/b)%b)){
                E[a].push_back(0);
                E[0].push_back(a);
            }
            else{
                E[a].push_back(b);
                E[b].push_back(a);
            }
        }
    }
    /*for(int i=0; i<10; i++){
        cout<<E[i].size()<<"\n";
    }
    cout<<"\n";*/
    for(int i=0; i<N; i++){
        //cout<<"a";
        if(E[i].size()>1){
            sort(E[i].begin(), E[i].end());
            for(int j=0; j<E[i].size()-1; j++){
                if(E[i][j]==E[i][j+1]){
                    cout<<2<<"\n";
                    return 0;
                }
            }
        }
    }
    int ans=N;
    for(int s:pierwsze){

        vector<int> V;
        V.push_back(s);
        d[s]=1;
        for(int i=0; i<V.size(); i++){
            int v=V[i];
            for(int u:E[v]){
                if(d[u]){
                    if(d[u]!=d[v]-1)    ans=min(ans, d[u]+d[v]-1);
                }
                else{
                    d[u]=d[v]+1;
                    V.push_back(u);
                }
            }
        }
        for(int i:V){
            d[i]=0;
        }
    }
    if(ans==N){
        cout<<"-1";
    }
    else cout<<ans;
}