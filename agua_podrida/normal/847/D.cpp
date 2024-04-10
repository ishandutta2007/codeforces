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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)

struct segmentSum{
    segmentSum(vi& values);
    segmentSum(int nn);

    void inc(int i);

    int sumr(int a, int b);

    int n;
    vi tree;
};

segmentSum::segmentSum(int nn) {
    n = nn;
    tree = vi(2*n);
}

segmentSum::segmentSum(vi& values) {
    n = values.size();
    tree = vi(2*n);
    F0(i,n) tree[n+i] = values[i];
    F1R(i,n-1) tree[i] = tree[2*i] + tree[2*i+1];
}

void segmentSum::inc(int i) {
    i += n;
    tree[i]++;
    for(i /= 2; i >= 1; i /= 2) tree[i] = tree[2*i] + tree[2*i+1];
}

int segmentSum::sumr(int a, int b) {
    a += n; b += n;
    int sum = 0;
    while(a <= b){
        if(a % 2 == 1) sum += tree[a++];
        if(b % 2 == 0) sum += tree[b--];
        a /= 2; b /= 2;
    }
    return sum;
}

bool cmp(pi a, pi b){
    return a.second - a.first < b.second - b.first;
}

void d(){
    int n,t;
    cin>>n>>t;
    vpi a(n);
    F0(i,n) {
        cin>>a[i].first;
        a[i].second = i+1;
    }
    vpi b = a;


    sort(todo(a),cmp);
    map<int,int> indexCompression;
    F0(i,n) indexCompression[a[i].first-a[i].second] = n-i-1;

    segmentSum st(n);

    int res = 0;
    int j = 0;
    F0(i,n){
        while(j < n and j+1 < t+a[i].second - a[i].first) {
            st.inc(indexCompression[b[j].first - b[j].second]);
            j++;
        }
        if(a[i].first >= a[i].second) maxi(res,st.sumr(0,indexCompression[a[i].first-a[i].second]));
    }

    int resi = 0;
    F0(i,n) {
        if(b[i].first + n - i < t) resi++;
    }
    maxi(res,resi);
    cout<<res<<'\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../evolution/evolution-11-common-endings.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    d();
    return 0;
}