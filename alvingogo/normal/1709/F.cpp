#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=998244353;
struct NTT{
	const int g=3;
	int bd,lgbd,x,invn;
	vector<int> rvb;
	vector<int> w,rw;
	int inv(int x){
		if(x==1){
			return 1;
		}
		return 1ll*(mod-mod/x)*inv(mod%x)%mod;
	}
	void rev(){
		rvb.resize(bd);
		int hbt=-1;
		for(int i=1;i<bd;i++){
			if(!(i&(i-1))){
				hbt++;
			}
			rvb[i]=rvb[i^(1<<(hbt))]|(1<<(lgbd-hbt-1));
		}
	}
	int po(int xx,int pp){
		int tt=xx,rr=1;
		while(pp){
			if(pp&1){
				rr=(1ll*rr*tt)%mod;
			}
			tt=(1ll*tt*tt)%mod;
			pp/=2;
		}
		return rr;
	}
	void calc(){
		x=po(g,(mod-1)/bd);
		w.resize(bd);
		rw.resize(bd);
		w[0]=1;
		for(int i=1;i<bd;i++){
			w[i]=1ll*w[i-1]*x%mod;
		}
		rw[bd-1]=inv(w[bd-1]);
		for(int i=bd-2;i>=0;i--){
			rw[i]=1ll*rw[i+1]*x%mod;
		}
	}
	void dft(vector<int> &a,bool flag){
		for(int i=0;i<bd;i++){
			if(i<rvb[i]){
				swap(a[i],a[rvb[i]]);
			}
		}
		int e,f;
		for(int l=1;l<bd;l<<=1){
			for(int g=0;g<bd;g+=2*l){
				for(int i=0;i<l;i++){
					e=a[g+i];
					if(flag){
						f=1ll*a[g+i+l]*rw[bd/l/2*i]%mod;
					}
					else{
						f=1ll*a[g+i+l]*w[bd/l/2*i]%mod;
					}
					a[g+i]=e+f;
					if(a[g+i]>=mod){
						a[g+i]-=mod;
					}
					a[g+i+l]=e-f;
					if(a[g+i+l]<0){
						a[g+i+l]+=mod;
					}
				}
			}
		}
		if(flag){
			for(int i=0;i<bd;i++){
				a[i]=1ll*a[i]*invn%mod;
			}
		}
	}
	void mul(vector<int> &a,vector<int> &b,vector<int> &c){
		lgbd=0;
		while((1<<lgbd)<a.size() || (1<<lgbd)<b.size()){
			lgbd++;
		}
		lgbd++;
		bd=(1<<lgbd);
		invn=inv(bd);
		rev();
		calc();
		vector<int> tmp(bd,0);
		c.resize(bd,0);
		for(int i=0;i<a.size();i++){
			c[i]=a[i];
		}
		for(int i=0;i<b.size();i++){
			tmp[i]=b[i];
		}
		for(int i=a.size();i<bd;i++){
			c[i]=0;
		}
		for(int i=b.size();i<bd;i++){
			tmp[i]=0;
		}
		dft(c,0); 
		dft(tmp,0);
		for(int i=0;i<bd;i++){
			c[i]=1ll*c[i]*tmp[i]%mod;
		}
		dft(c,1);
	}
};

void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int main(){
    AquA;
    NTT ntt;
    int n,k,f;
    cin >> n >> k >> f;
    vector<int> dp(k+1,1);
    for(int i=1;i<n;i++){
        vector<int> v;
        ntt.mul(dp,dp,v);
        vector<int> we(k+1,0);
        for(int j=0;j<=k;j++){
            we[j]=mul(k-j,v[j]);
        }
        for(int i=(int)v.size()-2;i>=0;i--){
            add(v[i],v[i+1]);
        }
        for(int j=0;j<=k;j++){
            add(we[j],v[j]);
        }
        dp=we;
    }
    vector<int> z;
    ntt.mul(dp,dp,z);
    if(f>=z.size()){
        cout << 0 << "\n";
        return 0;
    }
    cout << z[f] << "\n";
    return 0;
}