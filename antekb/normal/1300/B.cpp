#include<bits/stdc++.h>
using namespace std;
int tab[200005];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<2*n; i++){
            cin>>tab[i];
        }
        sort(tab, tab+2*n);
        cout<<tab[n]-tab[n-1]<<"\n";
    }
}