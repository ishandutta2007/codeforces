#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct no{
    set<int> ch;
    int sz=0;
};
vector<no> v;
vector<int> fib;
vector<int> che(200005);
pair<pair<int,int>,int> get(int x,int y,pair<int,int> ab){
    v[x].sz=1;
    for(auto h:v[x].ch){
        if(h==y){
            continue;
        }
        auto p=get(h,x,ab);
        if(p.sc>=0){
            return p;
        }
        v[x].sz+=v[h].sz;
    }
    if(v[x].sz==ab.fs || v[x].sz==ab.sc){
        return {{x,y},v[x].sz};
    }
    else{
        return {{-1,-1},-1};
    }
}
int dfs(int r,int sz){
    if(sz==1){
        return 1;
    }
    int t=che[sz];
    auto x=get(r,r,{fib[t-1],fib[t-2]}); 
    if(x.sc<0){
        return 0;
    }
    v[x.fs.fs].ch.erase(x.fs.sc);
    v[x.fs.sc].ch.erase(x.fs.fs);
    return dfs(x.fs.fs,x.sc) && dfs(x.fs.sc,sz-x.sc);
}
int main(){
    AquA;
    fib.push_back(0);
    fib.push_back(1);
    for(int i=2;;i++){
        int x=fib[i-1]+fib[i-2];
        if(x>200000){
            break;
        }
        fib.push_back(x);
        che[x]=i;
    }
    int n;
    cin >> n;
    if(che[n]==0){
        cout << "NO\n";
        return 0;
    }
    v.resize(n);
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].ch.insert(b);
        v[b].ch.insert(a);
    }
    if(dfs(0,n)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}