#include<bits/stdc++.h>
using namespace std;
const int A=200, N=200005;
int tab[A], tab2[N];
int main(){
    string t;
    int n;
    cin>>n>>t;
    int ans=0;
    for(int i=0; i<n; i++){
        tab2[i]=1;
        for(int j=t[i]+1; j<='z'+1; j++){
            tab2[i]=max(tab2[i], tab[j]+1);
            tab[t[i]]=max(tab[t[i]], tab[j]+1);
        }
        ans=max(ans, tab2[i]);
    }
    //cout<<ans<<"\n";
    if(ans<=2){
        cout<<"YES\n";
        for(int i=0; i<n; i++){
            cout<<(tab2[i]==1);
        }
    }
    else{
        cout<<"NO";
    }

}