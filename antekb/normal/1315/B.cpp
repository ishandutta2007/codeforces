#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        int a, b, p;
        cin>>a>>b>>p;
        cin>>s;
        char last='C';//s[s.size()-1];
        for(int i=s.size()-2; i>=0; i--){
            if(last!=s[i]){
                if(s[i]=='A'){
                    p-=a;
                }
                else{
                    p-=b;
                }
            }
            last=s[i];
            if(p<0){
                /*if(i<s.size()-1)*/cout<<i+2<<"\n";
                //else    cout<<s.size()<<"\n";
                break;
            }
            if(i==0){
                cout<<"1\n";
            }
        }
    }
}