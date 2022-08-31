#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
#define N (int) 2e5+3

ll n,m,u,v,t;
vector <pair<ll,ll>> b;
ll a[N],ans;
set <pair<ll,ll>> s;

bool sortt(const pair<int,int> &a, 
                   const pair<int,int> &b) 
{
        if(a.first == b.first)
            return a.second>b.second; 
        return a.first<b.first;
} 

int main(){ 
    cin>>t;
    while(t--){
        s.clear();
        b.clear();
        cin>>n;
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        cin>>m;
        for(int i = 0; i<m; i++){
            cin>>u>>v;
            b.push_back({u,v});
        }
        ll maxx = 0;
        sort(b.begin(),b.end());
        if(n == 1){
            if(b[m-1].first >= a[0]) cout<<1<<endl;
            else cout<<-1<<endl;
            continue;
        }
        for(int i = m-1; i > -1; i--){
            if(b[i].second > maxx){
                maxx = b[i].second;
                s.insert({b[i].first,maxx});
            }
        }
        ll ct = 0;
        ans = 0;
        /*
        for(int i = 0; i<m; i++){
            cout<<b[i].first<<" "<<b[i].second<<endl;
        }
        auto it = s.lower_bound({3,0});
        if(it == s.end())cout<<1;
        cout<<(*it).first<<" "<<(*it).second<<endl;
        */
        int key = 0;
        while(ct < n){
            auto it = s.lower_bound({a[ct],0});
            if(it == s.end()){
                key = 1;
                break;
            }
            maxx = 0;
            for(;it != s.end();it++){
                ll i;
                //cout<<ct<<" "<<(*it).first<<endl;
                for(i = 0; i < (*it).second; i++)
                    if((*it).first < a[i+ct]) break;
                if(i == (*it).second){
                    maxx = max(maxx,i);
                    break;
                }
                maxx = max(maxx,i);
                //cout<<maxx<<endl;
            }
            ct += maxx;
            ans++;
        }
        if(key == 1){
            cout<<-1<<endl;
        }
        else cout<<ans<<endl;
        fill_n(a,n,0);
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}