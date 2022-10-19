#include<bits/stdc++.h>
using namespace std;
#define int long long
const int NN=1e6;
bool vup[NN+5];
int n,X,Y,a[200100],mn[200100],mx[200100],pri[NN+5],lim,cnt[1<<20],MAXN,res;
void Ural(){
	vup[0]=vup[1]=true;
	for(int i=2;i<=NN;i++){
		if(!vup[i])pri[++pri[0]]=i;
		for(int j=1;i*pri[j]<=NN&&j<=pri[0];j++){
			vup[i*pri[j]]=true;
			if(!(i%pri[j]))break;
		}
	}
}
vector<pair<int,int> >xx,yy;
void part(int ip,vector<pair<int,int> >&v){
	for(int i=1;i<=pri[0];i++){
		if(ip%pri[i])continue;
		int cc=0;
		while(!(ip%pri[i]))cc++,ip/=pri[i];
		v.push_back(make_pair(pri[i],cc));
	}
	if(ip==1)return;
	int sqr=(int)(sqrt(ip)+0.5);
	if(sqr*sqr==ip){v.push_back(make_pair(sqr,2));return;}
	int gcd;
	for(int i=1;i<=n;i++){
		gcd=__gcd(ip,a[i]);
		if(gcd==1||gcd==ip)continue;
		v.push_back(make_pair(gcd,1));
		ip/=gcd;
		v.push_back(make_pair(ip,1));
		return;
	}
	gcd=__gcd(ip,X);
	if(gcd!=1&&gcd!=ip){
		v.push_back(make_pair(gcd,1));
		ip/=gcd;
		v.push_back(make_pair(ip,1));
		return;
	}
	gcd=__gcd(ip,Y);
	if(gcd!=1&&gcd!=ip){
		v.push_back(make_pair(gcd,1));
		X/=gcd;
		v.push_back(make_pair(ip,1));
		return;
	}
	v.push_back(make_pair(ip,1));
}
signed main(){
	scanf("%lld%lld%lld",&n,&X,&Y);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(Y%X){puts("0");return 0;}
	Ural();
	part(X,xx),sort(xx.begin(),xx.end());
	part(Y,yy),sort(yy.begin(),yy.end());
	for(int i=0;i<yy.size();i++)if(i>=xx.size()||xx[i].first!=yy[i].first)xx.insert(xx.begin()+i,make_pair(yy[i].first,0));
//	for(int i=0;i<xx.size();i++)printf("(%lld,%lld)",xx[i].first,xx[i].second);puts("");
//	for(int i=0;i<yy.size();i++)printf("(%lld,%lld)",yy[i].first,yy[i].second);puts("");
	for(int i=0;i<xx.size();i++)if(xx[i].second==yy[i].second)xx.erase(xx.begin()+i),yy.erase(yy.begin()+i);
//	for(int i=0;i<xx.size();i++)printf("(%lld,%lld)",xx[i].first,xx[i].second);puts("");
//	for(int i=0;i<yy.size();i++)printf("(%lld,%lld)",yy[i].first,yy[i].second);puts("");
	lim=xx.size(),MAXN=(1<<lim);
	for(int i=1;i<=n;i++){
		if(a[i]%X){mn[i]=-1;continue;}
		for(int j=0;j<lim;j++){
			int tmp=a[i],cc=0;
			while(!(tmp%xx[j].first))tmp/=xx[j].first,cc++;
			mn[i]|=(cc>xx[j].second)<<j;
		}
	}
	for(int i=1;i<=n;i++){
		if(Y%a[i]){mx[i]=-1;continue;}
		for(int j=0;j<lim;j++){
			int tmp=a[i],cc=0;
			while(!(tmp%yy[j].first))tmp/=yy[j].first,cc++;
			mx[i]|=(cc<yy[j].second)<<j;
		}
	}
	for(int i=1;i<=n;i++)if(mn[i]!=-1)cnt[mn[i]]++;
	for(int i=1;i<=n;i++){
		if(mx[i]==-1)continue;
		int W=(~mx[i])&(MAXN-1);
		for(int w=W;w;w=(w-1)&W)res+=cnt[w];
		res+=cnt[0];
	}
	printf("%lld\n",res);
//	for(int i=1;i<=n;i++)printf("%lld %lld\n",mn[i],mx[i]);
	return 0;
}
/*
1 273 255255
123
*/