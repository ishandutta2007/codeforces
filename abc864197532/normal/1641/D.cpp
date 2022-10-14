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
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 100005, logN = 18, K = 1 << 8, G = 3;

struct DS {
    vector <int> a, res;
    int w;
    bool operator < (const DS &o) {
        return w < o.w;
    }
};

template <typename T> // we can make this generic for any container [1]
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    std::size_t operator()(T const c) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t res = 0;
        for (int i : c)
            res ^= splitmix64(i + FIXED_RANDOM);
        return res;
    }
};

unordered_map <vector <int>, int, custom_hash<vector <int>>> id;
int _id, popcnt[32];

int get(vector <int> v) {
    if (id.count(v))
        return id[v];
    return id[v] = _id++;
}

#include<unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W(int n){static char buf[12],p;if(n<0)OB[OP++]='-',n=-n;if(n==0)OB[OP++]='0';p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];write(1,OB,OP);}

int main () {
    int n = R(), m = R();
    popcnt[0] = 1;
    for (int s = 1; s < 1 << m; ++s) {
        popcnt[s] = popcnt[s ^ ((-s) & s)] * -1;
    }
    vector <DS> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].a.resize(m), a[i].res.resize(1 << m);
        for (int &j : a[i].a)
            j = R();
        a[i].w = R();
        sort(all(a[i].a));
        vector <int> now;
        function <void(int, int)> gen = [&](int x, int id) {
            if (id == m) {
                a[i].res[x] = get(now);
                return;
            }
            gen(x, id + 1);
            now.pb(a[i].a[id]);
            gen(x | 1 << id, id + 1);
            now.pop_back();
        };
        gen(0, 0);
    }
    sort(all(a));
    vector <int> cnt(_id, 0);
    for (int i = 0; i < n; ++i) {
        for (int j : a[i].res)
            cnt[j]++;
    }
    int ans = INT_MAX;
    for (int i = 0, j = n - 1; i < n; ++i) {
        for (int j : a[i].res)
            cnt[j]++;
        int now = 0;
        while (i < j) {
            for (int k : a[j].res)
                cnt[k]--;
            now = 0;
            for (int s = 0; s < 1 << m; ++s)
                now += popcnt[s] * cnt[a[i].res[s]];
            if (now == 0) {
                for (int k : a[j].res)
                    cnt[k]++;
                break;
            }
            j--;
        }
        now = 0;
        for (int s = 0; s < 1 << m; ++s)
            now += popcnt[s] * cnt[a[i].res[s]];
        if (i == j)
            break;
        if (now > 0)
            ans = min(ans, a[i].w + a[j].w);
    }
    W(ans == INT_MAX ? -1 : ans);
}