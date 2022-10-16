#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef float f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
// SA-IS suffix array in O(N), is extremely fast
// includes LCP table with range minimum query
class Suffix_Array{
    unsigned char mask[8] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
    #define tget(i) ( (t[(i)/8]&mask[(i)%8]) ? 1 : 0 )
    #define tset(i, b) t[(i)/8]=(b) ? (mask[(i)%8]|t[(i)/8]) : ((~mask[(i)%8])&t[(i)/8])
    #define chr(i) (cs==sizeof(int)?((int*)s)[i]:((unsigned char *)s)[i])
    #define isLMS(i) (i>0 && tget(i) && !tget(i-1))

    // find the start or end of each bucket
    void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, sum = 0;
        for (i = 0; i <= K; i++)
            bkt[i] = 0;
        for (i = 0; i < n; i++)
            bkt[chr(i)]++;
        for (i = 0; i <= K; i++) {
            sum += bkt[i];
            bkt[i] = end ? sum : sum - bkt[i];
        }
    }
    void induceSAl(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, j;
        getBuckets(s, bkt, n, K, cs, end);
        for (i = 0; i < n; i++) {
            j = SA[i] - 1;
            if (j >= 0 && !tget(j))
                SA[bkt[chr(j)]++] = j;
        }
    }
    void induceSAs(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, j;
        getBuckets(s, bkt, n, K, cs, end);
        for (i = n - 1; i >= 0; i--) {
            j = SA[i] - 1;
            if (j >= 0 && tget(j))
                SA[--bkt[chr(j)]] = j;
        }
    }
    void SA_IS(unsigned char *s, int *SA, int n, int K, int cs) {
        int i, j;
        unsigned char *t = (unsigned char *) malloc(n / 8 + 1);
        tset(n-2, 0);
        tset(n-1, 1);
        for (i = n - 3; i >= 0; i--)
            tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)==1))?1:0);
        int *bkt = (int *) malloc(sizeof(int) * (K + 1));
        getBuckets(s, bkt, n, K, cs, true);
        for (i = 0; i < n; i++)
            SA[i] = -1;
        for (i = 1; i < n; i++)
            if (isLMS(i))
                SA[--bkt[chr(i)]] = i;
        induceSAl(t, SA, s, bkt, n, K, cs, false);
        induceSAs(t, SA, s, bkt, n, K, cs, true);
        free(bkt);
        int n1 = 0;
        for (i = 0; i < n; i++)
            if (isLMS(SA[i]))
                SA[n1++] = SA[i];
        for (i = n1; i < n; i++)
            SA[i] = -1;
        int name = 0, prev = -1;
        for (i = 0; i < n1; i++) {
            int pos = SA[i];
            bool diff = false;
            for (int d = 0; d < n; d++)
                if (prev == -1 || chr(pos+d) != chr(prev+d) || tget(pos+d) != tget(prev+d)) {
                    diff = true;
                    break;
                } else if (d > 0 && (isLMS(pos+d) || isLMS(prev+d)))
                    break;
            if (diff) {
                name++;
                prev = pos;
            }
            pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
            SA[n1 + pos] = name - 1;
        }
        for (i = n - 1, j = n - 1; i >= n1; i--)
            if (SA[i] >= 0)
                SA[j--] = SA[i];
        int *SA1 = SA, *s1 = SA + n - n1;
        if (name < n1)
            SA_IS((unsigned char*) s1, SA1, n1, name - 1, sizeof(int));
        else
            for (i = 0; i < n1; i++)
                SA1[s1[i]] = i;
        bkt = (int *) malloc(sizeof(int) * (K + 1));
        getBuckets(s, bkt, n, K, cs, true);
        for (i = 1, j = 0; i < n; i++)
            if (isLMS(i))
                s1[j++] = i;
        for (i = 0; i < n1; i++)
            SA1[i] = s1[SA1[i]];
        for (i = n1; i < n; i++)
            SA[i] = -1;
        for (i = n1 - 1; i >= 0; i--) {
            j = SA[i];
            SA[i] = -1;
            SA[--bkt[chr(j)]] = j;
        }
        induceSAl(t, SA, s, bkt, n, K, cs, false);
        induceSAs(t, SA, s, bkt, n, K, cs, true);
        free(bkt);
        free(t);
    }
    public:
    int* sa,* inv;
    vector<int> lcp, seg;
    int N;
    private:

    void make_lcp(const char*s){
        lcp.resize(N);
        int k=0;
        for(int i=0;i<N;++i){
            if(inv[i]!=0){
                for(int j = sa[inv[i]-1];s[i+k]==s[j+k];++k);
                lcp[inv[i]-1]=k;
                if(k)--k;
            }
        }
        lcp[N-1]=0;
        seg.resize(2*N);
        copy(lcp.begin(), lcp.end(), seg.begin()+N);
        for(int i=N-1;i>=0;--i)
            seg[i] = min(seg[2*i], seg[2*i+1]);
    }
    public:
    Suffix_Array(){}
    ~Suffix_Array(){delete[] sa; delete[] inv;}
    void build(string &s, int max_sigma=256){
        N=s.size();
        int *v = new int[N+3];
        SA_IS((unsigned char*)s.c_str(), v, N+1, max_sigma, 1);
        sa = new int[N]; inv = new int[N];
        for(int i=0;i<N;++i){
            sa[i] = v[i+1];
            inv[sa[i]] = i;
        }
        make_lcp(s.c_str());
        delete[] v;
    }
    int get_lcp(int i, int j){
        if(i==j) return 1e9;
        int ans = 1e9;
        for(i+=N, j+=N;i<j;i>>=1, j>>=1){
            if(i&1) ans = min(ans, seg[i++]);
            if(j&1) ans = min(ans, seg[--j]);
        }
        return ans;
    }
};


int arr[1000005];
void solve() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	s+=s.substr(0, k-1);
	Suffix_Array p;
	p.build(s);
	vi suffer;
	for(int i=0; i<sz(s); i++)
		if(p.sa[i]<n*k)
			suffer.pb(p.sa[i]);
	int g;
	cin>>g;
	fr(i,1,g) {
		string te;
		cin>>te;
		int lo=-1,hi=sz(suffer)-1,mid=(lo+hi+1)/2;
		while(lo<hi) {
			if(s.substr(suffer[mid],k)>te) {
				hi=mid-1;
			} else
				lo=mid;
			mid=(lo+hi+1)/2;
		}
		lo=0,hi=mid+1;
		int mid2=(lo+hi)/2;
		while(lo<hi) {
			if(s.substr(suffer[mid2],k)<te) {
				lo=mid2+1;
			} else
				hi=mid2;
			mid2=(lo+hi)/2;
		}
		trace(mid2,mid);
		for(int j=mid2; j<=mid; j++)
			arr[suffer[j]]=i;
	}
	for(int i=0; i<k; i++) {
		bool vlad=1;
		set<int> tolol;
		for(int j=i; j<n*k; j+=k) {
			if(arr[j]==0) {
				vlad=0;
				break;
			}
			tolol.insert(arr[j]);
		}
		if(vlad&&tolol.size()==n) {
			cout<<"YES"<<endl;
			for(int j=i; j<n*k; j+=k) {
				cout<<arr[j]<<" ";
			}
			cout<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}