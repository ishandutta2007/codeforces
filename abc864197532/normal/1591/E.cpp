#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000005, logC = 30, K = 450;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;

struct query {
    int l, k, id;
};

int a[N], cnt[N];
vector <int> adj[N];
vector <query> Q[N];
int ans[N];

void add(int v, int p) {
    oset.erase({cnt[v], v});
    cnt[v] += p;
    oset.insert({cnt[v], v});
}

void dfs(int v) {
    add(a[v], 1);
    for (query &i : Q[v]) {
        int p = oset.order_of_key({i.l, -1});
        if (p + i.k - 1 >= oset.size())
            ans[i.id] = -1;
        else {
            ans[i.id] = oset.find_by_order(p + i.k - 1)->Y + 1;
        }
    }
    for (int u : adj[v])
        dfs(u);
    add(a[v], -1);
}

#include<unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W1(int n){static char buf[12],p;if(n<0)OB[OP++]='-',n*=-1;p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]=' ';if(OP>65520)write(1,OB,OP),OP=0;}
inline void W2(int n){static char buf[12],p;if(n<0)OB[OP++]='-',n*=-1;p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]='\n';if(OP>65520)write(1,OB,OP),OP=0;}

int main () {
    int t = R();
    while (t--) {
        int n = R(), q = R();
        for (int i = 0; i < n; ++i)
            a[i] = R() - 1;
        for (int i = 1; i < n; ++i) {
            int p = R();
            adj[p - 1].pb(i);
        }
        for (int i = 0, v, l, k; i < q; ++i) {
            v = R() - 1, l = R(), k = R();
            Q[v].pb({l, k, i});
        }
        for (int i = 0; i < n; ++i)
            oset.insert({0, i});
        dfs(0);

        oset.clear();
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            Q[i].clear();
        }
        for (int i = 0; i < q - 1; ++i)
            W1(ans[i]);
        W2(ans[q - 1]);
    }
    write(1,OB,OP);
}