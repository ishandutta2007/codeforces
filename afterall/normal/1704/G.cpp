#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+100,M=1e5+10,Z=5e4;

int inputa[N];
int a[N];
ll inputb[N];
ll b[N];
vector <int> mola[N];
vector <int> molb[N];
ll sum[N];
ll getsum(ll l,ll r){
    if (l>r) swap(l,r);
    return 1ll * (r-l+1)*(r+l)/2;
}
bool ans[N];
ll firstcheck(int id,int e,ll val){
    int z=0;
    if (id%2==0) val+=sum[id],z=-(id/2);
    else val+=sum[id-1],z=-(id-1)/2;
   // cout << val  << endl;
    if (e<z) return 0;
    ll t=e-z;
    if (t>id) return 0;
    if (t==0){
        if (val==0) {
            return 1;
        }
        return 0;
    }
    if (getsum(id,id-t+1)<val) return 0;
    if (getsum(1,t)>val) return 0;
    return 1;
}
bool completecheck(ll i){
    ll z=inputb[1]-inputa[i];
    ll e=-(inputb[2]-(inputa[i+1]-z));
    if (firstcheck(i,e,z)){
        return 1;
    }
    if (firstcheck(i,e+1,z)){
        return 1;
    }
    return 0;
}
bool check(int id,int e,ll val){
//    cout << id << " hey " <<  e << ' ' << val << endl;
    int z=0;
    if (id%2==0) val+=sum[id],z=-(id/2);
    else val+=sum[id-1],z=-(id-1)/2;
   // cout << val  << endl;
    if (e<z) return 0;
    ll t=e-z;
    if (t>id) return 0;
    if (t==0){
        if (val==0) {
            reverse(ans+1,ans+id+1);
            for (int i=id-1;i>0;i-=2){
                ans[i]=1-ans[i];
            }
            return 1;
        }
        return 0;
    }
    if (getsum(id,id-t+1)<val) return 0;
    if (getsum(1,t)>val) return 0;

    for (int i=id;i;i--){
    //  cout << i << " hey " << getsum(i,i-t+1) << endl;
        if (getsum(i,i-t+1)==val){
            for (int j=i;j>=i-t+1;j--) ans[j]=1;
         //     cout << i << " dfn " << endl;
            break;
        }
        if (getsum(i-1,i-t)<val){
            ans[i]=1;
         // cout << i << " choose " << endl;
            val-=i;
            t--;
        }

    }

    reverse(ans+1,ans+id+1);
    for (int i=id-1;i>0;i-=2){
        ans[i]=1-ans[i];
    }
    return 1;
}
int good[N];
ll vis[N];
void Main(){
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        ans[i]=0;
        good[i]=0;
    }
    for (int i=1;i<=n;i++) cin >> inputa[i];
        for (int i=1;i<=n;i++) inputa[i]+=1e5;
    for (int i=3;i<=n;i++){
        a[i-2]=inputa[i-2]+2*inputa[i-1]+inputa[i];
    }
    int m;
    cin >> m;
    
    for (int i=1;i<=m;i++) cin >> inputb[i];
        for (int i=1;i<=m;i++){
            inputb[i]+=1e5;
        }
    for (int i=3;i<=m;i++){
        b[i-2]=inputb[i-2]+2*inputb[i-1]+inputb[i];
        if (b[i-2]<0){
            cout << -1 << endl;
            return ;
        }
        if (b[i-2]>N){
            cout << -1 << endl;
        }
    }
    vector <int> c;
    for (int i=1;i<=n-2;i++){
        mola[a[i]].pb(i);
    }
    for (int i=1;i<=m-2;i++){
        molb[b[i]].pb(i);
        c.pb(b[i]);
    }
    sort(c.begin(),c.end());
    c.resize(unique(c.begin(),c.end())-c.begin());
    if (n==2){
        if (inputa[1]==inputb[1]){
            if (inputa[2]==inputb[2]){
                cout << 0 << endl;
            }
            else if (inputa[2]+1==inputb[2]){
                cout << 1 << endl << 2 << endl;
            }
            else cout << -1 << endl;
        }
        else if (inputa[1]+1==inputb[1]){
            if (inputa[2]-2==inputb[2]){
                cout << 1 << endl << 1 << endl;
            }
            else if (inputa[2]-1==inputb[2]){
                cout << 2 << endl << 1 << " " << 2 << endl;
            }
            else cout << -1 << endl;
        }
        else{
            cout << -1 << endl;
            return ;
        }
        return ;
    }

    ll pp=0;
    for (auto u : c){
            vector <int> c;
            c=mola[u];
            for (auto v : mola[u-1]) c.pb(v);
            for (auto v : mola[u]) vis[v]=1;
            for (auto v : mola[u-1]) vis[v]=1;
            sort(c.begin(),c.end());
            if (c.size()<molb[u].size()) continue;
            if (molb[u].size()<3000){
        
            for (int i=0;i<c.size();i++){
                ll p1=1;
                for (auto j : molb[u]){
                  //  j=mobb[u][rand()%((ll)molb[u].size())];
                    if (j-molb[u][0]+c[i]>N || !vis[j-molb[u][0]+c[i]]){
                        p1=0;
                        break;
                    }
                }
                if (c[i]-molb[u][0]+1>0) good[c[i]-molb[u][0]+1]+=p1;
            }
            for (auto v : mola[u]) vis[v]=0;
            for (auto v : mola[u-1]) vis[v]=0;
                continue;
            }
        
        
        if (mola[u].size()>=Z){
            
                bitset<M> X;
                bitset<M> Y;
                for (auto v : mola[u]) X[v]=1;
                for (auto v : mola[u-1]) X[v]=1;
                for (auto v : molb[u]) Y[v-molb[u][0]]=1;
                ll z=0;
                ll cnt=0;
            
                for (auto v : c){
                    if (c.size()-cnt<molb[u].size() ) break;
                    cnt++;
                    if (v<molb[u][0] || v>n-m+molb[u][0]) continue;
                    if (completecheck(v-molb[u][0]+1)==0) continue;
                    if (molb[u].size()==1 || (((Y<<(v-z)) & X) == Y<<(v-z))){
                      //  cout << v << " HHHHHHH " <<  u << endl;
                        good[v-molb[u][0]+1]++;
                    }
                }
            
            
        }
        else{
            bitset<Z> X;
            bitset<Z> Y;
            for (auto v : mola[u]) X[v]=1;
            for (auto v : mola[u-1]) X[v]=1;
            for (auto v : molb[u]) Y[v-molb[u][0]]=1;
            ll z=0;
            ll cnt=0;
        
            for (auto v : c){
                if (c.size()-cnt<molb[u].size()) break;
                cnt++;
                if (v<molb[u][0] || v>n-m+molb[u][0]) continue;
                if (molb[u].size()==1 || (((Y<<(v-z)) & X) == Y<<(v-z))){
                  //  cout << v << " HHHHHHH " <<  u << endl;
                    good[v-molb[u][0]+1]++;
                }
            }
            
        }
    }
    for (int i=1;i<=n-m+1;i++){

        if (good[i]!=c.size()) continue;
                //cout << i << " iuhr " << endl;
        ll z=inputb[1]-inputa[i];
        ll e=-(inputb[2]-(inputa[i+1]-z));
        if (check(i,e,z)){
    
            for (int j=i;j<i+m-2;j++){
                if (b[j-i+1]>a[j]) ans[j+2]=1;
            }
            pp=1;
            break;
        }
        if (check(i,e+1,z)){
              
      
            ans[i+1]=1;
            for (int j=i;j<i+m-2;j++){
                if (b[j-i+1]>a[j]) ans[j+2]=1;
            }
            pp=1;
            break;
        }

    }
    
    if (pp){
        vector <int> w;
        for (int i=1;i<=n;i++) if (ans[i]) w.pb(i);
        cout << w.size() << endl;
        for (auto u : w) cout << u << " ";
        cout << endl;
    }
    else cout << -1 << endl;
    for (int i=1;i<=n-2;i++){
        mola[a[i]].clear();
    }
    for (int i=1;i<=m-2;i++){
        molb[b[i]].clear();
    }

}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    sum[1]=1;
    for (int i=2;i<N;i++){
        sum[i]=sum[i-2]+i;
    }
    while(t--) Main();
}