#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N=2e5+5;
int gdzie[N], tab[N], tab2[N], vis[N], ile[N];
pair<int, int> E[2][N];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>tab[i];
            ile[tab[i]]++;
        }
        for(int i=0; i<n; i++){
            cin>>tab2[i];
            ile[tab2[i]]++;
        }
        bool b=1;
        for(int i=1; i<=n; i++){
            if(ile[i]!=2){
                b=0;
                break;
            }
        }
        if(!b){
            cout<<"-1\n";
            for(int i=1; i<=n; i++){
                ile[i]=0;
            }
            continue;
        }
        for(int i=0; i<n; i++){
            if(tab[i]==tab2[i])continue;
            if(!gdzie[tab[i]])gdzie[tab[i]]=i+1;
            else{
                if(tab[gdzie[tab[i]]-1]==tab[i]){
                    E[0][i]={gdzie[tab[i]]-1, 1};
                    E[0][gdzie[tab[i]]-1]={i, 1};
                }
                else{
                    E[0][i]={gdzie[tab[i]]-1, 0};
                    E[1][gdzie[tab[i]]-1]={i, 0};
                }
            }
            if(!gdzie[tab2[i]])gdzie[tab2[i]]=i+1;
            else{
                if(tab2[gdzie[tab2[i]]-1]==tab2[i]){
                    E[1][i]={gdzie[tab2[i]]-1, 1};
                    E[1][gdzie[tab2[i]]-1]={i, 1};
                }
                else{
                    E[1][i]={gdzie[tab2[i]]-1, 0};
                    E[0][gdzie[tab2[i]]-1]={i, 0};
                }
            }
        }
        for(int i=0; i<n; i++){
            //cout<<gdzie[i+1]<<" ("<<E[0][i].st<<" "<<E[0][i].nd<<") ("<<E[1][i].st<<" "<<E[1][i].nd<<")\n";
        }
        //return 0;
        vector<int> V, V1, V2;
        for(int i=0; i<n; i++){
            if(tab[i]==tab2[i])continue;
            if(!vis[i]){
                vis[i]=1;
                int id=0, col=E[id][i].nd, wsk=E[id][i].st;
                id^=E[id][i].nd;
                V1.push_back(i);
                while(wsk!=i){
                    //cout<<wsk<<" "<<id<<" "<<col<<"\n";
                    vis[wsk]=1;
                    if(col==1)V2.push_back(wsk);
                    else V1.push_back(wsk);
                    col^=E[id][wsk].nd;
                    bool c=E[id][wsk].nd;
                    wsk=E[id][wsk].st;
                    id^=c;
                }
                if(V1.size()>V2.size()){
                    for(int j:V2){
                        V.push_back(j);
                    }
                }
                else{
                    for(int j:V1){
                        V.push_back(j);
                    }
                }
                V1.clear();
                V2.clear();
            }
        }
        cout<<V.size()<<"\n";
        for(int i:V){
            cout<<i+1<<" ";
        }
        cout<<"\n";
        for(int i=0; i<=n; i++){
            ile[i]=0;
            E[0][i]={0, 0};
            E[1][i]={0, 0};
            gdzie[i]=0;
            vis[i]=0;
        }
    }
}