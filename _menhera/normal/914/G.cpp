#include<bits/stdc++.h>
using namespace std;
const int MAXN = 131072;
const int lgMAXN = 17;
long long a[MAXN];
long long OR[MAXN];
long long XOR[MAXN];

const int MOD = 1e9+7;

namespace xorfft
{
    typedef long long base;
    void fft(vector<base> &a, bool inv){
	    int n = a.size(), j = 0;
	    for(int i=1; i<n; i++){
		    int bit = (n >> 1);
		    while(j >= bit){
			    j -= bit;
			    bit >>= 1;
		    }
		    j += bit;
		    if(i < j) swap(a[i], a[j]);
	    }
	    for(int i=2; i<=n; i<<=1){
		    int step = n / i;
		    for(int j=0; j<n; j+=i){
			    for(int k=0; k<i/2; k++){
				    base u = a[j+k], v = a[j+k+i/2];
				    a[j+k] = u+v;
				    a[j+k+i/2] = u-v;
			    }
		    }
	    }
	    if(inv) for(int i=0; i<n; i++) a[i] /= n;
    }
    vector<long long > multiply(vector<long long> &v){
	    vector<base> fv(v.begin(), v.end());
	    int n = MAXN;
	    fft(fv, 0);
	    for(int i=0; i<n; i++) fv[i] *= fv[i];
	    fft(fv, 1);
	    return fv;
    }
}


int f[MAXN];

vector<long long> sss(const vector<long long>& x)
{
    int N = x.size();
    if(N==1) return x;
    vector<long long> lh(x.begin(), x.begin()+N/2);
    vector<long long> uh(x.begin()+N/2, x.end());
    vector<long long> v1 = sss(lh);
    vector<long long> v2 = sss(uh);
    for(int i=0; i<N/2; ++i)
    {
        v1[i] += v2[i];
        v1[i] %= MOD;
        v1.push_back(v2[i]);
    }
    return v1;
}

vector<long long> andconv(vector<long long> v1, vector<long long> v2, vector<long long> v3)
{
    vector<long long> ans(MAXN);
    auto s1 = sss(v1); auto s2 = sss(v2); auto s3 = sss(v3);
    for(int i=0; i<MAXN; ++i)
    {
        ans[i] = s1[i]*s2[i]%MOD*s3[i]%MOD;
    }
    for(int x=MAXN-1; x>=0; --x)
    {
        for(int i=0; i=(i-x)&x;)
        {
            if(i!=x)
            {
                ans[i] += MOD- ans[x];
                ans[i] %= MOD;
            }
        }
    }
    return ans;
}
int main()
{
    int N; scanf("%d", &N);
    for(int i=0; i<N; ++i)
    {
        int t; scanf("%d", &t); ++a[t];
    }
    for(int x = 0; x<MAXN; ++x)
    {
        int y = MAXN-1-x;
        for(int i=0; i=(i-y)&y;)
        {
            OR[x|i] += a[x]*a[i]%MOD;
            OR[x|i] %= MOD;
        }
        OR[x] += a[x]*a[0]%MOD;
        OR[x] %= MOD;
    }
    vector<long long> fv(a, a+MAXN);
    vector<long long> xorconv = xorfft::multiply(fv);
    for(int i=0; i<MAXN; ++i)
        XOR[i] = xorconv[i]%MOD;
    
    f[0] = 0; f[1] = 1;
    for(int i=2; i<MAXN; ++i)
        f[i] = (f[i-1]+f[i-2])%MOD;
    
    for(int i=0; i<MAXN; ++i)
    {
        OR[i] = (OR[i] % MOD * f[i])%MOD;
        XOR[i] = (XOR[i] % MOD * f[i])%MOD;
        a[i] = (a[i] % MOD * f[i])%MOD;
    }
    vector<long long> orv(OR, OR+MAXN); 
    vector<long long> xorv(XOR, XOR+MAXN); 
    vector<long long> av(a, a+MAXN); 
    vector<long long> ans = andconv(orv, xorv, av);
    long long d = 0;
    for(int i=0; i<lgMAXN;++i)
    {
        d += ans[1<<i];
        d %= MOD;
    }
    
    printf("%lld\n", d);
    return 0;
}