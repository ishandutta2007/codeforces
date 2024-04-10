#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+3;
int mod=1e9+7;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,l,k;
    string s;
    cin>>n>>l>>k>>s;
    vector<char>v,ans[n];
    for(char i:s) v.push_back(i);
    sort(v.begin(),v.end());
    int p=0,p2=0;
    for(int i=0;i<l;i++){
        char cur=v[p];
        for(int j=p2;j<k;j++){
            if(cur!=v[p]){
                p2=j;
                cur=v[p];
            }
            ans[j].push_back(v[p++]);
        }
    }
    for(auto i:ans){
        int cnt=0;
        for(char j:i) cout<<j,cnt++;
        for(int j=cnt;j<l;j++) cout<<v[p++];
        cout<<'\n';
    }
}