#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+3;
int mod=1e9+7;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    int n=s.size(),cnt=1;
    vector<pair<int,int>>v;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]) cnt++;
        else{
            v.push_back({s[i-1]-'A',cnt});
            cnt=1;
        }
    }
    if(cnt) v.push_back({s[n-1]-'A',cnt});
    n=v.size();
    int p=n-1;
    for(int i=0;i<n;i++){
        if(v[i].first!=v[p].first){
            cout<<0;
            return 0;
        }
        else if(max(v[i].second,v[p].second)<2){
            cout<<0;
            return 0;
        }
        else if(i!=p){
            p--;
        }
        else{
            cout<<v[i].second+1<<'\n';
            return 0;
        }
    }
}