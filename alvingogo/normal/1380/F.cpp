#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

typedef vector<vector<int> > vvi;
const int mod=998244353;
struct no{
    int a[2][2]={0};
};
inline void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
inline int mul(int x,int y){
    return 1ll*x*y%mod;
}
inline no mu(no a,no b){
    int n=2;
    no c;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            for(int j=0;j<n;j++){
                add(c.a[i][j],mul(a.a[i][k],b.a[k][j]));
            }
        }
    }
    return c;
}
struct ST{
    vector<no> st;
    void init(int x){
        st.resize(4*x);
    }
    void update(int v,int L,int R,int p,no a){
        if(L==R){
            st[v]=a;
            return;
        }
        int m=(L+R)/2;
        if(p<=m){
            update(2*v+1,L,m,p,a);
        }
        else{
            update(2*v+2,m+1,R,p,a);
        }
        st[v]=mu(st[2*v+1],st[2*v+2]);
    }
    int query(){
        return st[0].a[0][0];
    }
}st;
int main(){
    AquA;
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    st.init(n);
    auto chg=[&](int i){
        no e;
        e.a[0][0]=s[i]-'0'+1;
        e.a[0][1]=1;
        if(i>0 && s[i-1]=='1'){
            e.a[1][0]=19-(10+s[i]-'0');
        }
        st.update(0,0,n-1,i,e);
    };
    for(int i=0;i<n;i++){
        chg(i);
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        x--;
        s[x]=y+'0';
        chg(x);
        if(x+1!=n){
            chg(x+1);
        }
        cout << st.query() << "\n";
    }
    return 0;
}