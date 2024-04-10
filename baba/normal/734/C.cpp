//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
pair<LL,LL> a[200005];
pair<LL,LL> b[200005];
int main(){
    LL n,m,k;
    sll(n);sll(m);sll(k);
    LL x,s;
    sll(x);sll(s);
    for(int i=0;i<m;i++) sll(a[i].S);
    for(int i=0;i<m;i++) sll(a[i].F);
    for(int i=0;i<k;i++) sll(b[i].S);
    for(int i=0;i<k;i++) sll(b[i].F);
    LL mxx = 0;
    for(int i=0;i<k;i++){
        if(b[i].F>s) continue;
        mxx = max(b[i].S,mxx);
    }
    LL mx = (n-mxx)*x;
    for(int i=0;i<m;i++){
        if(a[i].F>s) continue;
        LL c = a[i].F;
        int l = 0, r = k-1, ind = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(b[mid].F+c <= s){
                l = mid+1;
                ind = mid;
            }
            else{
                r = mid-1;
            }
        }
        LL ok;
        if(ind == -1) ok = 0;
        else ok = b[ind].S;
        LL ans = (a[i].S)*(n-ok);
        mx = min(ans,mx);
    }
    lldout(mx);
	return 0;
}