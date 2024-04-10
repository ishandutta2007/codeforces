#include<bits/stdc++.h>
using namespace std;
namespace fft{
	typedef complex<double> base;
	void fft(vector<base> &a, bool inv){
		int n = a.size(), j = 0;
		vector<base> roots(n/2);
		for(int i=1; i<n; i++){
			int bit = (n >> 1);
			while(j >= bit){
				j -= bit;
				bit >>= 1;
			}
			j += bit;
			if(i < j) swap(a[i], a[j]);
		}
		double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
		for(int i=0; i<n/2; i++){
			roots[i] = base(cos(ang * i), sin(ang * i));
		}
		/* In NTT, let prr = primitive root. Then,
		int ang = ipow(prr, (mod - 1) / n);
		if(inv) ang = ipow(ang, mod - 2);
		for(int i=0; i<n/2; i++){
			roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
		}
		Others are same. If there is /= n, do *= ipow(n, mod - 2).
		In XOR convolution, roots[*] = 1. 
		*/
		for(int i=2; i<=n; i<<=1){
			int step = n / i;
			for(int j=0; j<n; j+=i){
				for(int k=0; k<i/2; k++){
					base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
					a[j+k] = u+v;
					a[j+k+i/2] = u-v;
				}
			}
		}
		if(inv) for(int i=0; i<n; i++) a[i] /= n;
	}

	vector<long long> multiply( vector<int> &v, vector<int> &w){
		vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
		int n = 2; while(n < v.size() + w.size()) n <<= 1;
		fv.resize(n); fw.resize(n);
		fft(fv, 0); fft(fw, 0);
		for(int i=0; i<n; i++) fv[i] *= fw[i];
		fft(fv, 1);
		vector<long long> ret(n);
		for(int i=0; i<n; i++) ret[i] = (long long)round(fv[i].real());
		return ret;
    }
};
const int MOD = 1e3+9;
int N, M, K;
int cnt[201010];
vector<int> Do(vector<int>& v, vector<int>& w)
{
    int rsz = v.size()+w.size()-1;
    vector<long long> ans = fft::multiply(v, w);
    vector<int> wtf;
    for(int i=0; i<rsz; ++i)
        wtf.push_back(ans[i]%MOD);
    return wtf;
}
int main()
{
    using vi = vector<int>;
    auto cmp = [](const vector<int>&a, const vector<int>&b){ return a.size() > b.size(); };
    priority_queue<vi, vector<vi>, decltype(cmp)> Q(cmp);
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; ++i)
    {
        int t; scanf("%d", &t); cnt[t-1]++;
    }
    for(int i=0; i<M; ++i)
        Q.push(vector<int>(cnt[i]+1, 1));
    while(Q.size() != 1)
    {
        auto x = Q.top(); Q.pop();
        auto y = Q.top(); Q.pop();
        Q.push(Do(x, y));
    }
    printf("%d\n", Q.top()[K]);
    return 0;
}