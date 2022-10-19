#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int tab[N], tab2[N];
int main(){
    int n;
    cin>>n;
    if(n%2==1){
        cout<<"no";
        return 0;
    }
    int k=n/2;
    for(int i=0; i<n; i++){
        cin>>tab[i]>>tab2[i];
    }
    int x=tab[0]+tab[k], y=tab2[0]+tab2[k];
    for(int i=0; i<k; i++){
        if(tab[i]+tab[i+k]!=x or tab2[i]+tab2[i+k]!=y){
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
}