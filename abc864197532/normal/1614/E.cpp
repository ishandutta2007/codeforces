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
const int mod = 1e9 + 1, N = 200002, logN = 20, K = 1024, M = 1e9 + 1;

int cur[K], sz, sz2, l[K * 4], r[K * 4], t[K * 4], p[K * 4], sz3, sz4[K];
pii block[K][K * 4];

void build() {
    l[0] = 0, r[0] = M, t[0] = 0, sz3 = 1;
    for (int x : cur) {
        int m = sz3;
        for (int i = 0; i < m; ++i) {
            // [l r)
            // i - t
            if (r[i] <= x - t[i]) {
                t[i]++;
            } else if (x - t[i] < l[i]) {
                t[i]--;
            } else {
                if (l[i] < x - t[i])
                    l[sz3] = l[i], r[sz3] = x - t[i], t[sz3] = t[i] + 1, sz3++;
                if (x - t[i] + 1 < r[i])
                    l[sz3] = x - t[i] + 1, r[sz3] = r[i], t[sz3] = t[i] - 1, sz3++;
                l[i] = x - t[i], r[i] = x - t[i] + 1;
            }
        }
    }
    for (int i = 0; i < sz3; ++i)
        p[i] = i;
    sort(p, p + sz3, [&](int i, int j) {
        return l[i] < l[j];
    });
    for (int i = 0; i < sz3; ++i) {
        block[sz2][i] = mp(l[p[i]], t[p[i]]);
    }
    sz4[sz2++] = sz3;
}

int query(int x) {
    for (int i = 0; i < sz2; ++i) {
        auto it = upper_bound(block[i], block[i] + sz4[i], mp(x, 1 << 30)) - 1;
        x += it->Y;
    }
    for (int i = 0; i < sz; ++i) {
        if (x < cur[i])
            x++;
        else if (x > cur[i])
            x--;
    }
    return x;
}

#include<unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W(int n){static char buf[12],p;if(n==0)OB[OP++]='0';p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++] = '\n';if(OP>65520)write(1,OB,OP),OP=0;}


int main () {
    int lstans = 0, n = R();
    for (int i = 0, x, q; i < n; ++i) {
        x = R();
        cur[sz++] = x;
        if (sz == K) {
            build();
            sz = 0;
        }
        q = R();
        while (q--) {
            x = R();
            x += lstans;
            if (x >= M)
                x -= M;
            lstans = query(x);
            W(lstans);
        }
    }
    write(1,OB,OP);
}