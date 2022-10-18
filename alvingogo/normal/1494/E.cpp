#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n,m;
    cin >> n >> m;
    set<pair<int,int> > eq,df;
    map<pair<int,int>,char> mp;
    for(int i=0;i<m;i++){
        char c;
        cin >> c;
        if(c=='+'){
            int u,v;
            char b;
            cin >> u >> v >> b;
            if(mp.find(make_pair(v,u))!=mp.end()){
                if(mp[{v,u}]==b){
                    eq.insert({min(u,v),max(u,v)});
                }
                else{
                    df.insert({min(u,v),max(u,v)});
                }
            }
            mp[{u,v}]=b;
        }
        else if(c=='-'){
            int u,v;
            cin >> u >> v;
            if(eq.find({min(u,v),max(u,v)})!=eq.end()){
                eq.erase({min(u,v),max(u,v)});
            }
            if(df.find({min(u,v),max(u,v)})!=df.end()){
                df.erase({min(u,v),max(u,v)});
            }
            mp.erase({u,v});
        }
        else{
            int a;
            cin >> a;
            if(a%2==0){
                if(eq.empty()){
                    cout << "NO\n";
                }
                else{
                    cout << "YES\n";
                }
            }
            else{
                if(eq.empty() && df.empty()){
                    cout << "NO\n";
                }
                else{
                    cout << "YES\n";
                }
            }
        }   
    }
    return 0;
}