#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

typedef unsigned int u32;
inline int popcount(u32 x) {
    x = x - ((x >> 1) & 0x55555555); 
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    return ((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}
struct SimpleFID {
    int length, count, tablesize; vector<u32> blocks;
    vector<unsigned short> ranks;
    SimpleFID(int len): length(len) {
        tablesize = (len + 31) / 32;
        blocks.resize(tablesize + 1);
        ranks.resize(length + 1);
    }
    void set(int pos) { blocks[pos / 32] |= 1 << pos % 32; }
    void build() {
        count = 0;
        for(int i = 0; i < length; i ++) {
            ranks[i] = count;
            count += blocks[i / 32] >> i % 32 & 1;
        }
        ranks[length] = count;
    }
    inline int rank(int pos) const {
        return ranks[pos];
    }
    inline int rank(bool b, int pos) const { return b ? rank(pos) : pos - rank(pos); }
};
struct SimpleWaveletMatrix {
    typedef unsigned short Val;
    int length, bitsize; Val maxval;
    vector<SimpleFID> dicts; vector<int> mids;
    void init(const vector<Val>& data) {
        length = data.size();
        maxval = *max_element(data.begin(), data.end());
        if(1ULL << (8 * sizeof(Val) - 1) <= maxval) bitsize = 8 * sizeof(Val);
        else for(bitsize = 0; Val(1) << bitsize <= maxval; bitsize ++) ;
        dicts.assign(bitsize, length);
        mids.assign(bitsize, 0);
        vector<Val> datacurrent(data), datanext(length);
        for(int bit = 0; bit < bitsize; bit ++) {
            int pos = 0;
            for(int i = 0; i < length; i ++)
                if((datacurrent[i] >> (bitsize - bit - 1) & 1) == 0)
                    datanext[pos ++] = datacurrent[i];
            mids[bit] = pos;
            for(int i = 0; i < length; i ++)
                if((datacurrent[i] >> (bitsize - bit - 1) & 1) != 0)
                    dicts[bit].set(i), datanext[pos ++] = datacurrent[i];
            dicts[bit].build();
            datacurrent.swap(datanext);
        }
    }
    int rank_all(Val val, int left, int right, int& out_lt, int& out_gt) const {
        if(val > maxval) { out_lt = right - left; out_gt = 0; return 0; }
        out_lt = out_gt = 0;
        for(int bit = 0; bit < bitsize; bit ++) {
            bool dir = val >> (bitsize - bit - 1) & 1;
            int leftcount = dicts[bit].rank(dir, left), rightcount = dicts[bit].rank(dir, right);
            (dir ? out_lt : out_gt) += (right - left) - (rightcount - leftcount);
            left = leftcount, right = rightcount;
            if(dir) left += mids[bit], right += mids[bit];
        }
        return right - left;
    }
    inline int rank_lt(Val val, int left, int right) const {
        int tmp_lt, tmp_gt;
        rank_all(val, left, right, tmp_lt, tmp_gt);
        return tmp_lt;
    }
    inline int rangefreq(int left, int right, Val bottom, Val up) {
        return rank_lt(up, left, right) - rank_lt(bottom, left, right);
    }
};

int simu(vi a) {
    int n = a.size();
    int r = 0;
    for(int i = 1; i < n; i ++) {
        int j = i;
        while(j > 0 && a[j] < a[j-1]) {
            r ++;
            swap(a[j], a[j-1]);
            j = j - 1;
        }
    }
    return r;
}

int a[5000], cost[5000], costcosts[5000];
vi sorted[5000];
int getcost(int i, int x) {
    return i - (upper_bound(all(sorted[i]), x) - sorted[i].begin());
}
int main() {
    int n, xm = -1, ym = -1, mi = INF, micnt = 0;
    cin >> n;
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        vi v = vi(a, a+i);
        sort(all(v));
        sorted[i] = v;
    }
    vector<unsigned short> data;
    rep(i, n) data.pb(a[i]);
    SimpleWaveletMatrix w;
    w.init(data);

    rep(x, n) costcosts[x] = getcost(x, a[x]);
    vi randperm(n);
    rep(i, n) randperm[i] = i;
    random_shuffle(all(randperm));
    rep(xi, n) {
        int x = randperm[xi];
        int yxcost = costcosts[x];
        reu(y, x+1, n) {
           int t = 0;
            t -= costcosts[x];
            t -= costcosts[y];
            t += yxcost; // getcost(y, a[x]);

            if(a[y] < a[x]) t -= w.rangefreq(x+1, y, a[y]+1, a[x]);
            if(t <= mi) t += getcost(x, a[y]);
            if(a[x] < a[y]) if(t <= mi) t += w.rangefreq(x+1, y, a[x]+1, a[y]);
            if(t < mi) {
                xm = x;
                ym = y;
                mi = t;
                micnt = 0;
            }
            if(t == mi) micnt ++;
            yxcost += a[x] < a[y];
        }
    }

    cerr << mi << endl;
    int before = simu(vi(a,a+n));
    cerr << "before: "<<before << endl;
    swap(a[xm], a[ym]);
    int after = simu(vi(a,a+n));
    cerr << "after: " << after << endl;
    assert(before + mi == after);

    cout << after << " " << micnt << endl;
    return 0;
}