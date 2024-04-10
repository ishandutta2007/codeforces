#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

template <typename T, int MSZ>
struct BIT {
    int sz;
    T data[MSZ+1];

    void init(int inSz){
        sz = inSz;
    }

    inline void update(int i, T x){
        assert(i >= 0 && i < sz);
        for (++i; i <= sz; i += i & -i) data[i] += x;
    }

    // Sum of [0, i]
    inline T query(int i){
        assert(i >= -1 && i < sz);
        T res = 0;
        for (++i; i > 0; i -= i & -i) res += data[i];
        return res;
    }

    // Returns the smallest index i such that query(i) >= x or sz if there are no such indices
    // All values must be non-negative
    int lower_bound(T x){
        int i = 0;
        for (int pw = 1 << lg2(sz); pw > 0; pw >>= 1) {
            if(i + pw <= sz && data[i + pw] < x){
                x -= data[i += pw];
            }
        }
        return i;
    }
};

const int MN = 1e5 + 5;
int t, n, m;
int teachers[MN];
int arr[MN];
vi groups[MN];
ll gSum[MN];
BIT<int, MN> tree;
int numBad;
bool initGood;

bool solve1(int oldAvg, int newAvg){
    if(newAvg <= oldAvg) return true;
    int oldInd = lower_bound(arr, arr + m, oldAvg) - arr;
    assert(arr[oldInd] == oldAvg);
    int newInd = lower_bound(arr, arr + m, newAvg) - arr - 1;
    if(teachers[newInd] < newAvg) return false;
    if(newInd == oldInd) return true;
    int qRes = tree.query(newInd-1) - tree.query(oldInd-1);
    return !qRes;
}

bool solve2(int oldAvg, int newAvg){
    if(newAvg >= oldAvg) return false;
    int oldInd = lower_bound(arr, arr + m, oldAvg) - arr;
    assert(arr[oldInd] == oldAvg);
    int newInd = lower_bound(arr, arr + m, newAvg) - arr;
    if(teachers[newInd] < newAvg) return false;
    int numBetter = arr[newInd] > teachers[newInd];
    numBetter += tree.query(oldInd) - tree.query(newInd);
    assert(numBetter <= numBad);
    return numBetter == numBad;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> teachers[i];
        }
        for (int i = 0; i < m; i++) {
            int k; cin >> k;
            assert(k >= 2);
            for (int j = 0; j < k; j++) {
                int a; cin >> a;
                groups[i].pb(a);
                gSum[i] += a;
            }
            arr[i] = (gSum[i] + k-1)/k;
        }
        sort(teachers, teachers + n);
        rotate(teachers, teachers + n-m, teachers + n);
        sort(arr, arr + m);

        initGood = true;
        for (int i = 0; i < m; i++) {
            if(arr[i] > teachers[i]) initGood = false;
        }

        if(initGood){
             // tree[i] is teacher i can't handle group i+1
             tree.init(m);
             for (int i = 0; i < m-1; i++) {
                 tree.update(i, arr[i+1] > teachers[i]);
             }

             for(int i = 0; i < m; i++){
                 int k = SZ(groups[i]);
                 for(int s : groups[i]){
                     int oldAvg = (gSum[i] + k-1)/k;
                     int newAvg = (gSum[i]-s + k-2)/(k-1);
                     cout << solve1(oldAvg, newAvg);
                 }
             }
        }
        else {
            numBad = 0;
            bool reallyBad = false;
            // tree[i] is teacher i can't handle i but can handle i-1
            tree.init(m);
            for (int i = 1; i < m; i++) {
                if(teachers[i] < arr[i-1]) reallyBad = true;
            }
            for (int i = 0; i < m; i++) {
                if(teachers[i] < arr[i]){
                    numBad++;
                    tree.update(i, 1);
                }
            }
            if(reallyBad){
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < SZ(groups[i]); j++) {
                        cout << '0';
                    }
                }
            }
            else {
                for(int i = 0; i < m; i++){
                    int k = SZ(groups[i]);
                    for(int s : groups[i]){
                        int oldAvg = (gSum[i] + k-1)/k;
                        int newAvg = (gSum[i]-s + k-2)/(k-1);
                        cout << solve2(oldAvg, newAvg);
                    }
                }
            }
        }
        cout << '\n';

        // remember to reset everything
        for (int i = 0; i < m; i++) {
            groups[i].clear();
            gSum[i] = 0;
        }
        fill(tree.data, tree.data+m+1, 0);
    }
}