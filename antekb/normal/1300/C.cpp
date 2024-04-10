#include<bits/stdc++.h>
using namespace std;
int tab[100005], tab2[50];
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        tab[i]=k;
        for(int j=0; k>0; j++){
            tab2[j]+=k%2;
            k/=2;
        }
    }

    int x=0;
    for(int j=0; j<31; j++){
        //cout<<tab2[j]<<" ";
        if(tab2[j]<2){
            x+=(1<<j);
        }
    }
    //cout<<x;
    int id=0, maks=0;
    for(int i=0; i<n; i++){
        if((tab[i]&x)>maks){
            id=i;
            maks=(x&tab[i]);
        }
    }
    cout<<tab[id]<<" ";
    for(int i=0; i<n; i++){
        if(i!=id)   cout<<tab[i]<<" ";
    }
}