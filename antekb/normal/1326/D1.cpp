#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long H[N], H2[N], x=2463564, p=1e9+9, pot[N];
string s;
bool pal(int a, int b){
    //cout<<(((H[b+1]-H[a]*pot[b-a+1])%p+p)%p)<<" "<<(((H2[a]-H2[b+1]*pot[b-a+1])%p+p)%p)<<"\n";
    return ((((H[b+1]-H[a]*pot[b-a+1])%p+p)%p)==(((H2[a]-H2[b+1]*pot[b-a+1])%p+p)%p));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    pot[0]=1;
    for(int i=0; i<N-1; i++){
        pot[i+1]=(pot[i]*x)%p;
    }
    while(t--){
        cin>>s;
        int wsk=0;
        while(s[wsk]==s[s.size()-wsk-1] and 2*wsk<s.size()){
            wsk++;
        }
        if(2*wsk>s.size()){
            wsk--;
        }
        //cout<<"a";
        for(int i=0; i<s.size(); i++){
            H[i+1]=(H[i]*x+s[i]-'a')%p;
            //cout<<H[i+1]<<"\n";
        }
        H2[s.size()]=0;
        for(int i=s.size()-1; i>=0; i--){
            H2[i]=(H2[i+1]*x+s[i]-'a')%p;
            //cout<<H2[i]<<"\n";
        }
        int ans1=-1, ans2=-1;
        for(int i=wsk; i+wsk<s.size(); i++){
            if(pal(wsk, i)){
                ans1=i;
            }
        }
        for(int i=wsk; i+wsk<s.size(); i++){
            if(pal(i, s.size()-wsk-1)){
                ans2=i;
                break;
            }
        }
        for(int i=0; i<wsk; i++){
            cout<<s[i];
        }
        if(ans1!=-1 && (ans1>=(s.size()-ans2) || ans2==-1)){
            for(int i=wsk; i<=ans1; i++){
                cout<<s[i];
            }
        }
        else if(ans2!=-1){
            for(int i=ans2; i<s.size()-wsk; i++){
                cout<<s[i];
            }
        }
        for(int i=s.size()-wsk; i<s.size(); i++){
            cout<<s[i];
        }
        cout<<"\n";
    }
    //cout<<pal(1, 1);
}