#include<bits/stdc++.h>
#define N 2001000
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv_num(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	trav(x, in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	res.push_back(0);
	rep(i,0,sz(res)-1){	
		res[i+1]+=(long long)round(res[i])/1000;
		res[i]=(long long)round(res[i])%1000;
	}
	if(res.back()<1e-7) res.pop_back();
	return res;
}
char in[N];
int num[N];
bool cmp(const vd& a,int *og, int m){
	if(m>a.size()) return true;
	for(int i=m;i<a.size();i++){
		if((int)round(a[i])>0) return false;
	}
	for(int i=m-1;i>=0;i--){
		if((int)round(a[i])<og[i]) return true;
		else if((int)round(a[i])>og[i]) return false;
	}
	return false;
}
void mul3(vd &a){
	a.push_back(0);
	for(int i=0;i+1<a.size();i++){
		a[i]*=3;
	}
	for(int i=0;i+1<a.size();i++){
		a[i+1]+=(int)round(a[i])/1000;
		a[i]=(int)round(a[i])%1000;
	}
	if(a.back()<1e-7) a.pop_back();
}
int main(){
	scanf("%s",in);
	if(strcmp(in,"1")==0){
		puts("1");
		return 0;
	}
	int n=strlen(in),os=0;
	if(n%3){
		os=1;
		for(int j=0;j<n%3;j++) num[0]=num[0]*10+(in[j]-'0');
	}
	for(int i=0;i<n/3;i++){
		for(int j=i*3+n%3;j<(i+1)*3+n%3;j++){
			num[os+i]=num[os+i]*10+(in[j]-'0');
		}
	}
	int len=os+n/3,ans=1e8;
	double ap_log=(n-1)*log(10)+log((in[0]-'0')+1);
	reverse(num,num+len);
	for(int i=0;i<3;i++){
		vd res(1,pow(2,i));
		int p=round((ap_log-i*log(2))/log(3))-2;
		if(p<0) p=0;
		int tp=p;
		vd mul(1,3);
		while(tp){
			if(tp&1) res=conv_num(res,mul);
			mul=conv_num(mul,mul);
			tp>>=1;
		}
		while(cmp(res,num,len)){
			mul3(res);
			p++;
		}
		ans=min(i*2+p*3,ans);
	}
	printf("%d\n",ans);
	return 0;
}