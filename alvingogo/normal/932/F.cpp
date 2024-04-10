#include <bits/stdc++.h>
#pragma GCC optimize("O0")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct line{
    long long m,k;
    line(){
        m=0,k=1e18;
    }
    line(long long a,long long b){
        m=a,k=b;
    }
    long long val(long long x){
        return x*m+k;
    }
};
struct LI{
    struct no{
        line l;
        no* lch=nullptr,*rch=nullptr;
    };
    no* root=new no();
    int cnt=0;
    //vector<line> v;
    void insert(no* rt,int L,int R,line a){
        if(L==R){
            if(rt->l.val(L)>a.val(L)){
                rt->l=a;
            }
            return;
        }
        int m=L+(R-L)/2;
        if(rt->l.val(m)>a.val(m)){
            swap(rt->l,a);
        }
        if(rt->l.m<a.m){
            if(!rt->lch){
                rt->lch=new no();
            }
            insert(rt->lch,L,m,a);
        }
        else{
            if(!rt->rch){
                rt->rch=new no();
            }
            insert(rt->rch,m+1,R,a);
        }
    }
    long long query(no* rt,int L,int R,int x){
        if(L==R){
            return rt->l.val(x);
        }
        int m=(L+R)/2;
        if(x<=m){
            if(!rt->lch){
                return rt->l.val(x);
            }
            return min(rt->l.val(x),query(rt->lch,L,m,x));
        }
        else{
            if(!rt->rch){
                return rt->l.val(x);
            }
            return min(rt->l.val(x),query(rt->rch,m+1,R,x));
        }
    }
    void trav(no* rt,vector<line>& v){
        v.push_back(rt->l);
        if(rt->lch){
            trav(rt->lch,v);
        }
        if(rt->rch){
            trav(rt->rch,v);
        }
    }
    void add(line a){
        //v.push_back(a);
        insert(root,-1e5-8,1e5+8,a);
        cnt++;
    }
};

struct no2{
    vector<int> ch;  
    int idx;
    LI li;
    int a,b;
    long long dp=7e18;
};
vector<no2> v;
void dfs(int r,int f){
    for(auto h:v[r].ch){
        if(h!=f){
            dfs(h,r);
            v[r].dp=min(v[r].dp,v[v[h].idx].li.query(v[v[h].idx].li.root,-1e5-8,1e5+8,v[r].b));
        }
    }
    if(v[r].dp>6e18){
        v[r].dp=0;
    }
    v[r].li.add({v[r].a,v[r].dp});
    for(auto h:v[r].ch){
        if(h!=f){
            if(v[v[r].idx].li.cnt>v[v[h].idx].li.cnt){
                vector<line> p;
                v[v[h].idx].li.trav(v[v[h].idx].li.root,p);
                for(auto q:p){
                    v[v[r].idx].li.add(q);
                }
            }
            else{
                vector<line> p;
                v[v[r].idx].li.trav(v[v[r].idx].li.root,p);
                for(auto q:p){
                    v[v[h].idx].li.add(q);
                }
                v[r].idx=v[h].idx;
            }
        }
    }
}
int main(){
    AquA;
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i].b;
    }
    for(int j=0;j<n;j++){
        cin >> v[j].a;
        v[j].idx=j;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].ch.push_back(b);
        v[b].ch.push_back(a);
    }
    dfs(0,0);
    for(int i=0;i<n;i++){
        cout << v[i].dp << ' ';
    }
    cout << "\n";
    return 0;
}