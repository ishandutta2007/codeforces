#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

typedef pair<int, int> ii;

const int MAX_N = 200010;                        // up to 100K characters

char T[MAX_N];                                   // the input string
int n;                                           // the length of T
int RA[MAX_N], tempRA[MAX_N];                    // rank array
int SA[MAX_N], tempSA[MAX_N];                    // suffix array
int c[MAX_N];                                    // for counting/radix sort

char P[MAX_N];                                   // the pattern string
int m;                                           // the length of P

int Phi[MAX_N];                                  // for computing LCP
int PLCP[MAX_N];
// LCP[i] = the LCP between previous suffix T+SA[i-1] and suffix T+SA[i]
int LCP[MAX_N];

bool cmp(int a, int b) { return strcmp(T+a, T+b) < 0; } // compare

void constructSA_slow() {                        // max ~1000 characters
    for (int i = 0; i < n; ++i) SA[i] = i;         // this is the initial SA
    sort(SA, SA+n, cmp); // sort: O(n log n) * compare: O(n) = O(n^2 log n)
}

void countingSort(int k) {                       // O(n)
    int i, sum, maxi = max(300, n);                // up to 255 ASCII chars
    memset(c, 0, sizeof c);                        // clear frequency table
    for (i = 0; i < n; ++i)                        // count the frequency
        ++c[i+k < n ? RA[i+k] : 0];                  // of each integer rank
    for (i = sum = 0; i < maxi; ++i) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; ++i)                        // shuffle SA
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; ++i)                        // update SA
        SA[i] = tempSA[i];
}

void constructSA() {                             // can go up to 100K chars
    int i, k, r;
    for (i = 0; i < n; ++i) RA[i] = T[i];          // initial rankings
    for (i = 0; i < n; ++i) SA[i] = i;             // initial SA
    for (k = 1; k < n; k <<= 1) {                  // repeat log n times
        // this is actually radix sort: sort based on the second item
        // and then (stable) sort based on the first item
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;                       // re-ranking process
        for (i = 1; i < n; ++i)                      // compare adj suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
                    (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; ++i)                      // update RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;               // nice optimization
    }
}

void computeLCP_slow() {
    LCP[0] = 0;                                    // default value
    for (int i = 1; i < n; ++i) {                  // compute LCP by def
        int L = 0;                                   // always reset L to 0
        while (T[SA[i]+L] == T[SA[i-1]+L]) ++L;      // same L-th char, ++L
        LCP[i] = L;
    }
}

void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;                               // default value
    for (i = 1; i < n; ++i)                        // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];                        // remember prev suffix
    for (i = L = 0; i < n; ++i) {                  // compute PLCP in O(n)
        if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
        while (T[i+L] == T[Phi[i]+L]) ++L;           // L incr max n times
        PLCP[i] = L;
        L = max(L-1, 0);                             // L dec max n times
    }
    for (i = 0; i < n; ++i)                        // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]];                        // restore PLCP
}

ii stringMatching() {                            // in O(m log n)
    int lo = 0, hi = n-1, mid = lo;                // range = [0..n-1]
    while (lo < hi) {                              // find lower bound
        mid = (lo+hi) / 2;                           // this is round down
        int res = strncmp(T+SA[mid], P, m);          // find P in suffix 'mid'
        (res >= 0) ? hi = mid : lo = mid+1;          // notice the >= sign
    }
    if (strncmp(T+SA[lo], P, m) != 0) return ii(-1, -1); // if not found
    ii ans; ans.first = lo;
    lo = 0; hi = n-1; mid = lo;
    while (lo < hi) {                              // now find upper bound
        mid = (lo+hi) / 2;
        int res = strncmp(T+SA[mid], P, m);
        (res > 0) ? hi = mid : lo = mid+1;           // notice the > sign
    }
    if (strncmp(T+SA[hi], P, m) != 0) --hi;        // special case
    ans.second = hi;
    return ans;
} // return lower/upperbound as first/second item of the pair, respectively

ii LRS() {  // returns a pair (the LRS length and its index)
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; ++i)                        // O(n), start from i = 1
        if (LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}

int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }

ii LCS() {                 // returns a pair (the LCS length and its index)
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; ++i)                         // O(n), start from i = 1
        if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP)
            maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
}

void e(){
    string t;
    int q;
    cin>>t>>q;
    n = t.size();
    F0(i,t.size()) T[i] = t[i];
    T[n++] = '$';
    constructSA();

    vector<string> s(q);
    F0(i,q) cin>>s[i];
    vll dp(n);
    vll aux(n+1);

    F0(i,q){
        m = s[i].size();
        F0(j,m) P[j] = s[i][j];
        pi p = stringMatching();
        if(p.first >= 0) {
            aux[p.first]++;
            aux[p.second+1]--;
        }
    }

    F1(i,n) aux[i] += aux[i-1];
    F0(i,n) dp[SA[i]] = aux[i];

    vll dpr(n);
    aux = vll(n+1);

    reverse(T,T+n-1);
    constructSA();

    F0(i,q){
        m = s[i].size();
        reverse(todo(s[i]));
        F0(j,m) P[j] = s[i][j];
        pi p = stringMatching();
        if(p.first >= 0) {
            aux[p.first]++;
            aux[p.second+1]--;
        }
    }
    F1(i,n) aux[i] += aux[i-1];
    F0(i,n) dpr[SA[i]] = aux[i];
    dpr.pop_back();
    reverse(todo(dpr));
    ll res = 0;
    F1(i,n-1) res += dp[i]*dpr[i-1];
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    e();
    return 0;
}