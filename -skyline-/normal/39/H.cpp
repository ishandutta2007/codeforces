#include<iostream>
using namespace std;
int k,s,i,j;
int main(){
    cin>>k;
    for(i=1;i<k;i++){
        for(j=1;j<k;j++){
            s=i*j;
            if(s>=k)
                cout<<s/k;
            else if(j!=1)
                cout<<' ';
            cout<<s%k;
            cout<<' ';
        }
        cout<<'\n';
    }
        
    //return 0;
}