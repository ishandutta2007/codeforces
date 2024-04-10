#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

const int mod=3;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
    x+=mod*(x<0);
}
int mul(int x,int y){
    return x*y%mod;
}
int inv(int x){
    return x;
}
struct GE{
    vector<vector<int> > v;
    int m;
    void init(int x){
        m=x;
        v.resize(x+1);
    }  
    int ins(vector<int> a){
        for(int i=0;i<m;i++){
            if(a[i]!=0){
                if(v[i].empty()){
                    v[i]=a;
                    return 1;
                }
                int z=(mod-a[i])%mod;
                for(int j=i;j<=m;j++){
                    add(a[j],mul(mul(z,inv(v[i][i])),v[i][j]));
                }
            }
        }
        if(a[m]!=0){
            return -1;
        }
        return 1;
    }
    vector<int> print(){
        vector<int> ans(m);
        for(int i=m-1;i>=0;i--){
            if(v[i].empty()){
                ans[i]=1;
            }
            else{
                ans[i]=mul(inv(v[i][i]),v[i][m]);
            }
            for(int j=0;j<i;j++){
                if(v[j].empty()){
                    continue;
                }
                add(v[j][m],-mul(v[j][i],ans[i]));
            }
        }
        return ans;
    }
};
int main(){
	AquA;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        GE ge;
        ge.init(m);
        vector<vector<int> > e(n,vector<int>(n,-1));
        vector<int> c(m);
        int f=0;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b >> c[i];
            a--;
            b--;
            e[a][b]=e[b][a]=i;
            if(c[i]!=-1){
                vector<int> v(m+1);
                v[i]=1;
                v[m]=c[i]%mod;
                ge.ins(v);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(e[i][j]!=-1 && e[i][k]!=-1 && e[j][k]!=-1){
                        vector<int> v(m+1);
                        v[e[i][j]]=v[e[i][k]]=v[e[j][k]]=1;
                        f=min(f,ge.ins(v));
                    }
                }
            }
        }
        if(f==-1){
            cout << -1 << "\n";
            continue;
        }
        auto ans=ge.print();
        for(auto j:ans){
            cout << (j==0?3:j) << " ";
        }
        cout << "\n";
    }
	return 0;
}