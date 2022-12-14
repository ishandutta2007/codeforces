#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
const int N=40010;
vector<int> divisor;
int a[N],b[N];
void get_divisor(int n){ //
	for(int i=1;i<n;i=n/(n/(i+1)))
	if(n%i==0)
		divisor.push_back(i);
	return divisor.push_back(n);
}
ll count(int a[],int n,int d){
	//int p=lower_bound(a,a+n,d)-a;
	ll ans=0;
	repeat(i,0,n)
	if(a[i]-(d-1)>0)
		ans+=a[i]-(d-1);
	return ans;
}
int input(int a[],int n){
	int len=0,cnt=0;
	a[cnt++]=0;
	repeat(i,0,n){
		if(read())len++;
		else if(cnt>0)a[cnt++]=len,len=0;
	}
	if(len>0)a[cnt++]=len;
	sort(a,a+cnt);
	return cnt;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n=read(),m=read();
	ll k=read(); get_divisor(k);
	n=input(a,n); m=input(b,m);
	ll ans=0;
	for(auto d:divisor){
		ans+=count(a,n,d)*count(b,m,k/d);
	}
	cout<<ans<<endl;
	return 0;
}