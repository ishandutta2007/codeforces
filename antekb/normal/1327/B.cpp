#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int czy[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a=0, wolna;
        for(int i=0; i<n; i++){
            int k;
            cin>>k;
            bool b=1;
            for(int j=0; j<k; j++){
                int x;
                cin>>x;
                if(b && !czy[x]){
                    czy[x]=1;
                    b=0;
                    a++;
                }
            }
            if(b and a==i) wolna=i+1;
        }
        if(a==n)    cout<<"OPTIMAL\n";
        else{
            cout<<"IMPROVE\n";
            cout<<wolna<<" ";
            for(int i=1; i<=n; i++){
                if(!czy[i]){ cout<<i<<"\n";
                    break;
                }
            }
        }
        for(int i=1; i<=n; i++){
            czy[i]=0;
        }

    }
}