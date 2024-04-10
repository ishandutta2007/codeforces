/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli maxN = 150000L;
const lli mod = 998244353LL;
lli modpow(lli b, lli e) {
	lli ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }

        if (number != 0 || length == 0)
            write_char(number + '0');

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}

template<typename T>
struct bit{
// Ref - https://codeforces.com/contest/1208/submission/59476716
	lli n;
	vector<T> fen;
	bit(): n(0) {}
	bit(lli _n) : n(_n), fen(_n+10) {}
	void add(lli p,T val){
		for(;p <= n;p += p & -p)
			fen[p] += val;
	}
	T sum(lli p){
		T ans = 0;
		for(;p > 0;p -= p & -p)
			ans += fen[p];
		return ans;
	}
};

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,d;
    string s;
    vi e[maxN+5];
    lli tin[maxN+5],tout[maxN+5],lazy[maxN+5],par[maxN+5],hd[maxN+5];
    bool sp[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void dfs(lli u,lli p)
{
    par[u]=p;
    tin[u]=++T;
    vi b;
    for(auto x:e[u])
    {
        if(x==p)
            continue;
        dfs(x,u);
        b.pb(x);
    }

    e[u].swap(b);
    sort(all(e[u]),[&](const lli a,const lli b){
        return tout[a]-tin[a]>tout[b]-tin[b];
    });

    if(!e[u].empty())
        sp[e[u][0]]=true;
    tout[u]=T+1;
}

void dfs2(lli u,lli head)
{
    dbg(u,head);
    hd[u]=head;
    if(e[u].empty())
        return;
    lli cnt=0;
    for(auto x:e[u])
    {
        if(cnt)
            dfs2(x,x);
        else
            dfs2(x,head);
        cnt++;
    }
}

lli sub(lli n)
{
    return tout[n]-tin[n];
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    IO::init();
    lli q;
    // cin>>n>>q;
    IO::read_int(n, q);
    const lli nn=modpow(n,mod-2);

    fo(i,n-1)
    {
        // cin>>u>>v;
        IO::read_int(u, v);
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(1,0);
    dfs2(1,1);

    sp[0]=sp[1]=true;

    bit<lli> bt(T);

    while(q--)
    {
        // cin>>T>>v;
        IO::read_int(T, v);
        // dbg(T,v);
        if(T==1)
        {
            // cin>>d;
            IO::read_int(d);
            lazy[v]+=d;

            dbg(v,sub(v),d*sub(v));
            bt.add(tin[1],d*sub(v));
            // bt.add(tout[1],-d*sub(v));

            bt.add(tin[v],-d*sub(v));
            bt.add(tout[v],d*sub(v));

            bt.add(tin[v],d*n);
            bt.add(tin[v]+1,-d*n);
            if(e[v].empty())
                continue;

            v=e[v][0];
            d*=n-sub(v);
            bt.add(tin[v],d);
            bt.add(tout[v],-d);
        }
        else
        {
            lli ans=0;
            ans+=bt.sum(tin[v]);

            v=hd[v];
            while(v)
            {
                lli d=lazy[par[v]];
                d*=n-sub(v);
                ans+=d;
                dbg(v,hd[v]);
                v=hd[par[v]];
            }

            ans%=mod;
            ans*=nn;
            ans%=mod;
            // cout<<ans<<endl;
            IO::write_int((int) ans, '\n');
        }
    }

}   aryanc403();
    return 0;
}