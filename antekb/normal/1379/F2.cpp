#include<bits/stdc++.h>
using namespace std;
const int N=(1<<18)+5;
int tab[2*N], tab2[2*N];
bool czy[2*N];
set<int> S1[N];
set<int> S2[N];
void quer1(int id, int val){
    //cout<<"a";
    //cout<<id<<" "<<val<<"a\n";
    for(id+=N, tab[id]=val, czy[id]=(tab[id]<=tab2[id]), id/=2; id>0; id/=2){
        czy[id]=(tab[2*id+1]<=tab2[2*id])&&czy[2*id]&&czy[2*id+1];
        tab[id]=max(tab[2*id], tab[2*id+1]);
    }
}
void quer2(int id, int val){
    //cout<<"a";
    //cout<<id<<" "<<val<<"b\n";
    for(id+=N, tab2[id]=val, czy[id]=(tab[id]<=tab2[id]), id/=2; id>0; id/=2){
        czy[id]=(tab[2*id+1]<=tab2[2*id])&&czy[2*id]&&czy[2*id+1];
        //cout<<id<<" "<<czy[id]<<"\n";
        tab2[id]=min(tab2[2*id], tab2[2*id+1]);
    }
}
int main(){
    int n, m, q;
    cin>>n>>m>>q;
    for(int i=0; i<2*N; i++){
        czy[i]=1;
        tab2[i]=2*m+5;
    }
    while(q--){
        int x, y;
        cin>>x>>y;
        if(!(x&1)){
            x--;
            x/=2;
            if(S1[x].find(-y)==S1[x].end()){
                S1[x].insert(-y);
                quer1(x, -*S1[x].begin());
            }
            else{
                S1[x].erase(S1[x].find(-y));
                quer1(x, (S1[x].size()==0) ? 0 : -(*(S1[x].begin())));
            }
        }
        else{
            x--;
            x/=2;
            if(S2[x].find(y)==S2[x].end()){
                S2[x].insert(y);
                quer2(x, *S2[x].begin());
            }
            else{
                S2[x].erase(S2[x].find(y));
                quer2(x, (S2[x].size()==0) ? 2*m+5 : *(S2[x].begin()));
            }
        }
        if(czy[1]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}