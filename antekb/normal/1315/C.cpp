#include<bits/stdc++.h>
using namespace std;
int tab[205];
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
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            tab[x]=1;
            V.push_back(x);
        }
        vector<int> V2;
        bool b=1;
        for(int i:V){
            b=0;
            for(int j=i+1; j<=2*n; j++){
                if(tab[j]==0){
                    tab[j]=1;
                    b=1;
                    V2.push_back(j);
                    break;
                }
            }
            if(!b){
                break;
            }
        }
        if(!b){
            cout<<"-1\n";
        }
        else{
            for(int i=0; i<n; i++){
                cout<<min(V[i], V2[i])<<" "<<max(V[i], V2[i])<<" ";
            }
            cout<<"\n";
        }
        for(int i=0; i<=2*n; i++){
            tab[i]=0;
        }
    }
}