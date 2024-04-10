#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

map<int,int> mp;
int ans=1e9;
int mt=0;
int query(int x){
    if(mp.find(x)!=mp.end()){
        return mp[x];
    }
    if(x<mt){
        return 0;
    }
    cout << "? " << x << endl;
    cin >> mp[x];
    if(mp[x]){
        ans=min(ans,mp[x]*x);
    }
    return mp[x];
}
int main(){
    int n;
    cin >> n;
    int l=1,r=4042000;
    while(r>l){
        int m=(l+r)/2;
        if(query(m)!=1){
            l=m+1;
        }
        else{
            r=m;
        }
    }
    query(l);
    int sum=l;
    for(int i=2;i<=n;i++){
        r=(sum-1)/i;
        query(r);
    }
    cout << "! " << ans << endl;
	return 0;
}