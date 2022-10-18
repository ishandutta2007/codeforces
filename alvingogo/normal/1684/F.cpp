#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        map<int,vector<int> > m;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            m[v[i]].push_back(i);
        }
        multiset<int> s;
        vector<pair<int,int> > pp(n,{1e9,1e9}),vq(q);
        for(int i=0;i<q;i++){
            cin >> vq[i].fs >> vq[i].sc;
            vq[i].fs--;
            vq[i].sc--;
            //s.insert(vq[i].fs);
        }
        int mx=0,mn=n+1;
        sort(vq.begin(),vq.end(),[&](pair<int,int> a,pair<int,int> b){return a.sc<b.sc;});
        int rr=q-1;
        for(int i=n-1;i>=0;i--){
            while(rr>=0 && vq[rr].sc>=i){
                s.insert(vq[rr].fs);
                rr--;
            }
            m[v[i]].pop_back();
            if(s.empty()){
                continue;
            }
            if(m[v[i]].size()){
                auto y=lower_bound(m[v[i]].begin(),m[v[i]].end(),*s.begin());
                if(y==m[v[i]].end()){
                    continue;
                }
                pp[i].sc=m[v[i]][m[v[i]].size()-1];
                pp[i].fs=*y;
                mx=max(mx,pp[i].sc);
                mn=i;
            }
        }
        int ans=n+1;
        multiset<int> s2;
        s2.insert(1e9);
        for(int i=n-1;i>=mx;i--){
            ans=min(ans,i-min(*s2.begin(),mn)+1);
            s2.insert(pp[i].fs);
            s2.insert(pp[i].sc);
        }
        cout << max(ans,0) << "\n";
    }
    return 0;
}