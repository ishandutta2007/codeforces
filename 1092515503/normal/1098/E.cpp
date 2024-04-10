/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[50100],b[100100],s[100100];
ll S[100100];
vector<int>v[100100],u;
ll f(ll a,ll b,ll c,ll n){
	// printf("FUFUFU:%lld,%lld,%lld,%lld\n",a,b,c,n);
	if(a>=c||b>=c)return f(a%c,b%c,c,n)+(n*(n+1)>>1)*(a/c)+(n+1)*(b/c);
	if(!a)return (n+1)*(b/c);
	ll m=(a*n+b)/c;
	return n*m-f(c,c-b-1,a,m-1);
}
ll count(ll val){
	ll ret=0;
	for(int r=1,l=1;r<=m;r++){
		int R=1;
		while(R<=b[r]){
			// printf("[%d,%d]:%d,%lld\n",l,r,R,ret);
			if(S[r]-S[l-1]<val){ret+=1ll*(s[r-1]-s[l-1])*(b[r]-R+1)+(1ll*(0ll+R+b[r])*(b[r]-R+1)>>1);break;}
			if(r==l){
				if((val-1)/r>=b[r])ret+=1ll*(R+b[r])*(b[r]-R+1)>>1;
				else if((val-1)/r<=R)ret+=((val-1)/r)*(b[r]-R+1);
				else{
					int qwq=(val-1)/r;
					ret+=(0ll+R+qwq)*(qwq-R+1)>>1;
					ret+=1ll*qwq*(b[r]-qwq);
				}
				break;
			}
			if(S[r-1]+1ll*r*R-S[l]>=val){l++;continue;}
			// printf("|%d,%d|\n",l,r);
			int _l=R,_r=r[b];
			while(_l<_r){
				int _m=(0ll+_l+_r+1)>>1;
				if(S[r-1]+1ll*r*_m-S[l]>=val)_r=_m-1;else _l=_m;
			}
			// printf("|%d,%d|\n",l,r);
			int _p=_r;
			_l=R,_r++;
			while(_l<_r){
				int _m=(0ll+_l+_r)>>1;
				if((val-(S[r-1]+1ll*r*_m-S[l])-1)/l<=b[l])_r=_m;else _l=_m+1;
			}
			// printf("|%d,%d|\n",l,r);
			// printf("<%d,%d,%d>\n",R,_p,_l);
			ret+=1ll*(s[r-1]-s[l])*(_p-R+1)+(1ll*(0ll+R+_p)*(_p-R+1)>>1);
			// printf("GUGU:%lld\n",ret);
			ll rem=val-(S[r-1]+1ll*r*_p-S[l])-1;
			// printf("FUHU:%lld\n",rem);
			ret+=1ll*b[l]*(_l-R);
			if(_l<=_p)ret+=f(r,rem,l,_p-_l);
			R=_p+1;
		}
	}
	// printf("%lld:%d\n",val,ret);
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v[a[i]].push_back(i),m=max(m,a[i]);
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j+=i)for(auto x:v[j])u.push_back(x);
		sort(u.begin(),u.end());
		for(int l=0,r=0;l<(int)u.size();l=r+1){
			r=l;
			while(r+1<(int)u.size()&&u[r+1]==u[r]+1)r++;
			b[i]+=1ll*(r-l+1)*(r-l+2)>>1;
		}
		u.clear();
	}
	for(int i=m;i;i--)for(int j=(i<<1);j<=m;j+=i)b[i]-=b[j];
	// for(int i=1;i<=m;i++)printf("%d ",b[i]);puts("");
	for(int i=1;i<=m;i++)s[i]=s[i-1]+b[i],S[i]=S[i-1]+1ll*b[i]*i;
	ll h=1ll*s[m]*(s[m]+1)>>1;
	h=(h+1)>>1;
	// printf("HH:%d\n",h);
	// count(66);
	ll l=0,r=1e18;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(count(mid)<h)l=mid;else r=mid-1;
	}
	printf("%lld\n",l);
	return 0;
}
/*
16
2 6 18 12 60 15 10 4 2 6 18 12 60 15 10 4 
*/