#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    t=1;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        for(int i=0; i<4*k; i++){
            int a;
            cin>>a;
        }
        cout<<n*m+n+m-3<<"\n";
        for(int i=1; i<n; i++){
            cout<<"U";
        }
        for(int i=1; i<m; i++){
            cout<<"R";
        }
        int a=0;
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                if(a) cout<<"R";
                else cout<<"L";
            }
            a=!a;
            if(i!=n-1) cout<<"D";
        }
        cout<<"\n";
    }
}