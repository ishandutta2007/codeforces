#include<bits/stdc++.h>

using namespace std;
const int N=200005;
int tab[N];
int main(){
    int n, a, b, k;
    cin>>n>>a>>b>>k;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        x=(x-1)%(a+b);
        tab[i]=x;
    }
    //cout<<tab[0];
    sort(tab, tab+n);
    int ans=0;
    for(int i=0; i<n; i++){
        if(tab[i]/a<=k){
            //cout<<tab[i]<<""" ";
            if(tab[i]>=a)   k-=tab[i]/a;
            ans++;
        }
        else{
            break;
        }
    }
    //cout<<k;
    cout<<ans;
}