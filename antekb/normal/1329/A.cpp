#include<bits/stdc++.h>
#define st first
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N=1e6+5;
int main(){
    int n, m;
    cin>>n>>m;
    long long sum=0;
    vi V;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        sum+=x;
        V.push_back(x);
        if(x+i>n){
            cout<<"-1";
            return 0;
        }
    }
    if(sum<n){
        cout<<"-1";
        return 0;
    }
    ll cnt=0;
    int l=0;
    for(int i=0; i<m; i++){
        cnt+=V[i];
        if(n-(sum-cnt)<V[i]+i){
            cout<<i+1<<" ";
            //l=i;
        }
        else{
            cout<<n-(sum-cnt)-V[i]+1<<" ";
        }
    }
}