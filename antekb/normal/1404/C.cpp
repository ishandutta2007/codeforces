#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=(1<<19), INF=1e9+5, mod=1e9+7;
int tab[2*N];
int Find(int k){
    int i;
    for(i=1; i<N;){
        if(tab[2*i+1]>=k){
            i=2*i+1;
        }
        else{
            k-=tab[2*i+1];
            i<<=1;
        }
    }
    return i-N;
}
void add(int id){
    for(id+=N; id>0; id>>=1){
        tab[id]++;
    }
}
int tab2[N], tab3[N], ans[N], tab4[2*N];
void sub(int id){
    for(id+=N; id>0; id>>=1){
        tab4[id]--;
    }
}
int sum(int l, int r){
    int res=0;
    for(l+=N, r+=N; l<r; l>>=1, r>>=1){
        if(l&1){
            res+=tab4[l++];
        }
        if(r&1){
            res+=tab4[--r];
        }
    }
    return res;
}
int main(){
    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>tab2[i];
        if(i<tab2[i]){
            tab3[i]=0;
        }
        else{
                //cout<<Find(tab2[i]-i)
            tab3[i]=min(Find(i-tab2[i]), i);
            add(tab3[i]);
        }
        //cout<<tab3[i]<<"\n";
    }
    vector<pair<pii, pii> > V;
    for(int i=0; i<q; i++){
        int x, y;
        cin>>x>>y;
        V.pb(mp(mp(x, 1), mp(y, i)));
    }
    for(int i=1; i<=n; i++){
        V.pb(mp(mp(tab3[i], 0), mp(0, i)));
    }
    sort(V.begin(), V.end());
    //reverse(all(V));
    //cout<<"\n";
    for(int i=2*N-1; i>0; i--){
        if(i>=N)tab4[i]=1;
        else tab4[i]=tab4[2*i]+tab4[2*i+1];
    }
    for(int i=0; i<V.size(); i++){
        if(!V[i].st.nd){
            sub(V[i].nd.nd-1);
            //cout<<V[i].nd.nd<<"\n";
        }
        else{
            ans[V[i].nd.nd]=sum(V[i].st.st, n-V[i].nd.st);
            //cout<<ans[V[i].nd.nd]<<" "<<V[i].st.st<<" "<<n-V[i].nd.st<<"\n";
        }
    }
    //cout<<"\n";
    for(int i=0; i<q; i++){
        cout<<ans[i]<<"\n";
    }
}