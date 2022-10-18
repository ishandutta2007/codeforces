#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n,d;
    cin >> n >> d;
    vector<pair<int,int> > b,c;
    for(int i=0;i<n;i++){
        int s,a;
        cin >> s >> a;
        if(s<d){
            continue;
        }
        if(s>=a){
            b.push_back({s,a});
        }
        else{
            c.push_back({s,a});
        }
    }
    sort(b.begin(),b.end());
    sort(c.begin(),c.end(),[&](pair<int,int> e,pair<int,int> f){return e.sc<f.sc;});
    int ans=0;
    int k=0;
    for(auto h:b){
        while(k<c.size()){
            if(h.fs>=c[k].sc){
                if(d<=c[k].fs){
                    ans++;
                    d=c[k].sc;
                }
                k++;
            }
            else{
                break;
            }
        }
        if(d<=h.fs){
            d=max(d,h.sc);
            ans++;
        }
    }
    while(k<c.size()){
        if(d<=c[k].fs){
            ans++;
            d=max(d,c[k].sc);
        }
        k++;
    }
    cout << ans << "\n";
    return 0;
}