#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int maks=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        cout<<x+maks<<" ";
        if(x>0){
            maks+=x;
        }
    }
}