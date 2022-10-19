#include<bits/stdc++.h>
using namespace std;
//const int N=100005;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n;
        long long suma=0, zera=0;
        for(int i=0; i<n; i++){
            cin>>k;
            if(!k){
                zera++;
            }
            suma+=k;
        }
        cout<<zera+(zera+suma==0)<<"\n";
    }
}