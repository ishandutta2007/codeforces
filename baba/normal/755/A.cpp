// Willpower alone isn't enough in battle 
// You know that, *
// Defeating ** will require far more..
// ~ Armin Arlert, SnK

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector< VI > VVI;

typedef long long int LL;

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

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define endl '\n'
const int N = 1e6 + 10;
int primes[N];
void sieve() {
    primes[0] = primes[1] = 1;
    for(LL i=0;i<N;i++)
        if(!primes[i])
            for(LL j=2*i;j<N;j+=i)
                primes[j] = 1;
    return;
}
int main()
{
    sieve();
    fast_io;
    int n;
    cin >> n;
    for(int j=1;j<=1000;j++)
        if(primes[j*n+1])
            return 0*printf("%d\n",j);
    return 0;
}