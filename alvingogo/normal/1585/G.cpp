#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct no{
    vector<int> ch;
    vector<int> sg;
    multiset<int> m;
    int val=0;
    int id=0;
};
vector<no> v;
void dfs(int r){
    if(v[r].ch.size()==0){
        v[r].id=r;
        v[r].val=1;
        v[r].sg={0};
        v[r].m.insert(0);
        return;
    }
    else if(v[r].ch.size()==1){
        dfs(v[r].ch[0]);
        v[r].id=v[v[r].ch[0]].id;
        v[v[r].id].sg.push_back(v[v[r].ch[0]].val);
        v[v[r].id].m.insert(v[v[r].ch[0]].val);
        v[r].val=v[v[r].ch[0]].val+1;
        while(v[v[r].id].m.find(v[r].val)!=v[v[r].id].m.end()){
            v[r].val++;
        }
        return;
    }
    int maxx=-1;
    for(auto h:v[r].ch){
        dfs(h);
        v[v[h].id].sg.push_back(v[h].val);
        if(maxx==-1 || v[v[h].id].sg.size()<v[maxx].sg.size()){
            maxx=v[h].id;
        }
    }
    int u=v[maxx].sg.size();
    v[r].id=r;
    v[r].sg.resize(u);
    for(auto h:v[r].ch){
        for(int i=u-1;i>=0;i--){
            int j=(int)v[v[h].id].sg.size()-(u-i);
            v[r].sg[i]^=v[v[h].id].sg[j];
        }
    }
    for(int i=0;i<u;i++){
        v[r].m.insert(v[r].sg[i]);
    }
    while(v[r].m.find(v[r].val)!=v[r].m.end()){
        v[r].val++;
    }
}
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        v.clear();
        v.resize(n);
        vector<int> rt;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            a--;
            if(a<0){
                rt.push_back(i);
            }
            else{
                v[a].ch.push_back(i);
            }
        }
        int ans=0;
        for(auto h:rt){
            dfs(h);
            ans^=v[h].val;
        }
        cout << ((ans!=0)?"YES\n":"NO\n");
    }
    return 0;
}