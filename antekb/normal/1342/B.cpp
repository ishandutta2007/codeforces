#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=1e5+5, INF=1e9+5;

int main(){
    int t;
    cin>>t;
    while(t--){
        string t;
        cin>>t;
        bool b=1;
        for(int i=1; i<t.size(); i++){
            if(t[i]!=t[i-1]){
                b=0;
            }
        }
        if(b){
            cout<<t<<"\n";
        }
        else{
            for(int i=0; i<t.size(); i++){
                cout<<"01";
            }
            cout<<"\n";
        }
    }
}