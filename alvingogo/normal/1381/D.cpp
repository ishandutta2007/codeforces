#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct no{
    vector<int> ch;
    vector<int> s;
    int bg=0;
    int mb=0;
};
vector<no> v;
void dfs(int r,int f){
    for(auto h:v[r].ch){
        if(h!=f){
            dfs(h,r);
            v[r].s.push_back(v[h].bg+1);
            v[r].bg=max(v[r].bg,v[h].bg+1);
        }
    }
    while(v[r].s.size()<3){
        v[r].s.push_back(0);
    }
}
void dfs2(int r,int f){
    sort(v[r].s.begin(),v[r].s.end(),greater<int>());
    for(auto h:v[r].ch){
        if(h!=f){
            v[h].s.push_back(v[r].s[v[r].s[0]==v[h].bg+1]+1);
            dfs2(h,r);
        }
    }
}
int lth=0;
vector<int> zz;
int dfs3(int r,int f,int b){
    int ab=(r==b);
    for(auto h:v[r].ch){
        if(h!=f){
            if(dfs3(h,r,b)){
                ab=1; 
                lth++;  
                zz.push_back(r);
            }
            else{
                v[r].mb=max(v[r].mb,v[h].mb+1);
            }
        }
    }
    return ab;
}
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        a--;
        b--;
        v.clear();
        v.resize(n);
        for(int i=1;i<n;i++){
            int c,d;
            cin >> c >> d;
            c--;
            d--;
            v[c].ch.push_back(d);
            v[d].ch.push_back(c);
        }
        dfs(0,0);
        dfs2(0,0);
        lth=0;
        zz.clear();
        dfs3(a,a,b);
        int flag=0;
        for(int i=0;i<n;i++){
            if(v[i].s[2]>=lth){
                flag=1;
            }
            //cout << i << " " << v[i].bg << " " << v[i].s[0] << " " << v[i].s[1] << " " << v[i].s[2] << "\n";
        }
        if(!flag){
            cout << "NO\n";
            continue;
        }
        reverse(zz.begin(),zz.end());
        zz.push_back(b);
        int l=0,r=lth;
        int mr=lth-v[zz[0]].mb,ml=v[zz[lth]].mb;
        while(l<r){
            if(l<ml){
                l++;
                mr=min(mr,lth+l-v[zz[l]].mb);
            }
            else if(r>mr){
                r--;
                ml=max(ml,v[zz[r]].mb-(lth-r));
            }
            else{
                break;
            }
        }
        cout << ((l==r)?"YES\n":"NO\n");
    }
    return 0;
}