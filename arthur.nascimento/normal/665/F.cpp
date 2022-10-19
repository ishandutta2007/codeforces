#include <bits/stdc++.h>
#define sq(x) ((x)*(x))
#define pb push_back
#define debug 
typedef long long ll;
using namespace std;

const int N = 1000000;
const int K = 15000000;

map<int,ll> dp[10100];

int memo[5*N];
int num[5*N];
int pk[5*N];
int stamp = 0;

ll n;

int least[2*K];
ll primes[2*N];
int tp;

int upperK[505000];

ll get0(ll ni,int k){
    if(k == 0) return 0;
    if(n/ni < K){
        num[stamp] = n/ni;
        pk[stamp] = k;
        //debug("add qry %d %d\n",n/ni,k);
        stamp++;
        return 0;
    }
    assert(ni <= 10000);
    k = min(k,upperK[ni]);
    if(dp[ni].find(k) != dp[ni].end()) return 0;
    dp[ni][k] = 1;
    get0(ni,k-1);
    get0(ni*primes[k-1],k-1);
    return 0;
}

ll get(ll ni,int k){
    if(k == 0)
        return n/ni-1;
    if(n/ni < K){
       if(num[stamp] != n/ni)
            debug("got %lld %d should be %lld %d\n",num[stamp],pk[stamp],n/ni,k);
       // assert(num[stamp] == n/ni);
      //  assert(pk[stamp] == k);
        //debug("dp %lld %d = %d\n",n/ni,primes[k],memo[stamp]);
        return memo[stamp++];
    }
    int kk = min(k,upperK[ni]);
    if(dp[ni].find(kk) != dp[ni].end()){
        ll ret = dp[ni][kk];
       // debug("dp %lld %d = %d\n",n/ni,primes[k],ret-(k-kk));
        return ret - (k - kk);
    }
    dp[ni][k] = get(ni,k-1);
    dp[ni][k] -= (get(ni*primes[k-1],k-1)+1);
    //debug("dp %lld %d = %d\n",n/ni,primes[k],dp[ni][k]);
    return dp[ni][k];
}

struct ev {
    int type, num, id, pri;
    ev(int type=0,int num=0,int id=0): type(type), num(num), id(id){
        if(type == 1)
            pri = least[num];
        else
            pri = primes[pk[id]];
    }
    bool operator<(ev comp) const {
        if(pri != comp.pri)
            return pri > comp.pri;
        return type > comp.type;
    }
};

int T[2*K];
void upd(int idx){
    while(idx < 2*K){
        T[idx]++;
        idx += idx&-idx;
    }
}
int qry(int idx){
    int r = 0;
    while(idx){
        r += T[idx];
        idx -= idx&-idx;
    }
    return r;
}

int main() {
    scanf("%lld",&n);
    tp = 0;
    for(int i=2;i<=K;i++)
        if(least[i] == 0){
            least[i] = i;
            primes[tp++] = i;
            if(i > 10000) continue;
            for(int j=i*i;j<=K;j+=i)
                if(least[j] == 0)
                    least[j] = i;
        } 
    upperK[0] = tp-1;
    for(int i=1;i<501000;i++){
        upperK[i] = upperK[i-1];
        while(upperK[i] > 0 && sq(primes[upperK[i]-1]) > n/i)
            upperK[i]--;
    }
   
    for(int i=0;primes[i]*primes[i]<=n;i++){
        //debug("-> %d %d\n",primes[i],upperK[primes[i]]);
        get0(primes[i],upperK[primes[i]]);
    }
    debug("%d\n",stamp);
    for(int i=0;i<10100;i++)
        dp[i].clear();
    
    vector<ev> v;
    for(int i=2;i<=K;i++)
        v.pb(ev(1,i,0));
    for(int i=0;i<stamp;i++)
        v.pb(ev(0,0,i));
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i].type == 1){
            upd(v[i].num);
            //debug("add %d least %d\n",v[i].num,least[v[i].num]);   
        }
        else {
            memo[v[i].id] = qry(num[v[i].id]);
            //debug("num %d pk %d -> %d\n",num[v[i].id], primes[pk[v[i].id]],memo[v[i].id]);    
        }
    }
    
    v.clear();
        
    stamp = 0;
    
    ll ans = 0;
    
    for(int i=0;primes[i]*primes[i]*primes[i] <= n; i++)
        ans++;
        
    
    for(int i=0;primes[i]*primes[i]<=n;i++){
        ll u = get(primes[i],upperK[primes[i]]) + upperK[primes[i]];
        ans += u;
        debug("%lld primes upto %lld/%d = %lld\n",u,n,primes[i],n/primes[i]);
    }
    int ptr = tp-1;
    while(primes[ptr]*primes[ptr] > n) ptr--;
    ll y = 0;
    for(int i=0;primes[i]*primes[i]<=n;i++){
        while(primes[ptr] * primes[i] > n)
            ptr--;
        y += ptr;
    }
    ans -= y/2;
    for(int i=0;primes[i]*primes[i]<=n;i++)
        ans--;
    printf("%lld\n",ans);
}