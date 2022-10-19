#include<bits/stdc++.h>
#define st first
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int m, d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>d>>m;
        int k=1;
        vi V;
        while(k<=d){
            V.push_back(min(2*k-1, d)-k+2);
            k<<=1;
        }
        long long ans=1;
        for(int i:V){
            ans*=i;
            ans%=m;
            //cout<<i<<" ";
        }
        cout<<(ans+m-1)%m<<"\n";
    }
}