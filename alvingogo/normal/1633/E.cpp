#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int n,m;
    cin >> n >> m;
    struct eg{
        pair<int,int> e;
        int w;
    };
    vector<eg> v(m);
    vector<pair<int,int> > k;
    for(int i=0;i<m;i++){
        cin >> v[i].e.fs >> v[i].e.sc >> v[i].w;
        v[i].e.fs--;
        v[i].e.sc--;
        v[i].w*=2;
        k.push_back({v[i].w,i});
    }
    vector<pair<int,pair<int,int> > > p;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            p.push_back({(v[i].w+v[j].w)/2,{i,j}});
        }
        p.push_back({v[i].w,{0,0}});
    }
    p.push_back({0,{0,0}});
    sort(p.begin(),p.end());
    vector<int> x(m);
    sort(k.begin(),k.end());
    for(int i=0;i<m;i++){
        x[k[i].sc]=i;
    }
    struct DSU{
        vector<int> bo;
        void init(int nn){
            bo.resize(nn);
            iota(bo.begin(),bo.end(),0);
        }
        int find(int w){
            return bo[w]==w?w:bo[w]=find(bo[w]);
        }  
        int merge(int w,int y){
            w=find(w);
            y=find(y);
            if(w==y){
                return 0;
            }
            bo[w]=y;
            return 1;
        }
    };
    vector<pair<int,pair<int,int> > > st;
    for(int i=0;i<p.size();i++){
        auto h=p[i];
        if((k[x[h.sc.fs]].fs<k[x[h.sc.sc]].fs) xor (x[h.sc.fs]>x[h.sc.sc])){
            swap(k[x[h.sc.fs]],k[x[h.sc.sc]]);
            swap(x[h.sc.fs],x[h.sc.sc]);
        }
        if(i!=p.size()-1 && h.fs==p[i+1].fs){
            continue;
        }
        DSU d;
        d.init(n);
        int delta=0,ans=0;
        int p=0;
        for(auto y:k){
            if(d.merge(v[y.sc].e.fs,v[y.sc].e.sc)){
                ans+=abs(y.fs-h.fs);
                p++;
                if(y.fs>h.fs){
                    delta--;
                }
                else{
                    delta++;
                }
            }
        }
        st.push_back({h.fs,{ans,delta}});
    }
    cout << endl;
    auto query=[&](int z){
        z*=2;
        pair<int,pair<int,int> > a={z,{1e9,1e9}};
        auto y=upper_bound(st.begin(),st.end(),a);
        y=prev(y);
        auto t=*y;
        return (t.sc.fs+t.sc.sc*(z-t.fs))/2;
    };
    int q,qk,a,b,c;
    cin >> q >> qk >> a >> b >> c;
    int xr=0;
    for(int i=0;i<q;i++){
        int z;
        cin >> z;
        xr^=query(z);

        if(i==q-1){
            for(int j=i+1;j<qk;j++){
                z=(a*z+b)%c;
                xr^=query(z);
            }
        }
    }
    cout << xr << "\n";
    return 0;
}