#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 222222;
const int MO = 998244353;
int n,m,a[N],b[N],t[N];
LL l[N],r[N],s[N];
void ad(int x,int y){
	while(x<=m){
		t[x]+=y;
		x+=x&-x;
	}
}
int qu(int x){
	x--;
	int y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y;
}
map<LL,int> M;
map<LL,int>::iterator it;
LL solve(int st,int ed,LL d){
	if(st-1>ed)
		return 0;
	int i;
	LL ans;
	n=0;
	for(i=st;i<=ed;i++)
		a[++n]=b[i];
	l[0]=0,r[n]=0;
	for(i=1;i<=n;i++)
		l[i]=l[i-1]+a[i];
	for(i=n;i>=1;i--)
		r[i-1]=r[i]+a[i];
	s[0]=0;
	for(i=1;i<=n;i++)
		s[i]=-s[i-1]+a[i];
	ans=0;
	M.clear();
	for(i=0;i<=n;i+=2)
		M[l[i]-s[i]+d]=-1,M[r[i]-s[i]]=-1;
	m=0;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++m;
	for(i=0;i<=n;i+=2){
		ad(M[l[i]-s[i]+d],1);
		ans+=qu(M[r[i]-s[i]]);
	}
	for(i=0;i<=m;i++)
		t[i]=0;
	M.clear();
	for(i=1;i<=n;i+=2)
		M[l[i]-s[i]+d]=-1,M[r[i]-s[i]]=-1;
	m=0;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++m;
	for(i=1;i<=n;i+=2){
		ad(M[l[i]-s[i]+d],1);
		ans+=qu(M[r[i]-s[i]]);
	}
	for(i=0;i<=m;i++)
		t[i]=0;
	//cout<<st<<' '<<ed<<' '<<d<<' '<<ans<<endl;
	return ans;
}
int main(){
	int T,i,o;
	LL s,w,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&o);
		w=0;
		for(i=1;i<=o;i++)
			scanf("%d",b+i),w+=b[i];
		if(o==1){
			printf("1\n");
			continue;
		}
		if(o==2){
			printf("%d\n",1+(b[1]!=b[2]));
			continue;
		}
		s=1;
		x=0;
		for(i=1;i<=o;i++){
			x+=b[i];
			if(x>w-x&&i>=1&&i<=o-1)
				s++;
		}
		s+=solve(2,o-1,b[1]-b[o]);
		s+=solve(2,o-2,b[1]-b[o-1]+b[o]);
		s+=solve(3,o-1,-b[1]+b[2]-b[o]);
		s+=solve(3,o-2,-b[1]+b[2]-b[o-1]+b[o]);
		printf("%d\n",s%MO);
	}
	return 0;
}