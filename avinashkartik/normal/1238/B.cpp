#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main(){
    int t ;
    cin>>t;
    while(t--){
        ll n,r;
        cin>>n>>r;
        set <double> l;
        ll x;
        for(int i = 0;i<n;i++){
            cin>>x;
            l.insert(x);
        }
        ll ct = 0;
        ll len = l.size();
        ll y =0;
        for(auto i : l){
            //cout<<i<<" "<<ct<<"\n";
            if(len - y <= ceil(i/r))
                ct++;
            y++;
        }
        cout<<ct<<endl;
    }
}