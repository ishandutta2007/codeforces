#include<bits/stdc++.h>
using namespace std;
char _[999999],*U,*V;
#define I (U==V&&(V=(U=_)+fread(_,1,999991,stdin),U==V)?0:*U++)
//void in(int&x){char c=I;for(x=0;c>'9'||c<'0';c=I);for(;c<='9'&&c>='0';c=I)x=x*10+c-48;}
void in(int&x){scanf("%d",&x);} 
void exgcd(int a,int b,int&x,int&y){b?(exgcd(b,a%b,y,x),y-=a/b*x):(x=1,y=0);}
const int N=1e5+3,M=2e5+3;
set<int>a[M],b[M];
vector<tuple<int,int,int>>v;
map<int,int>mp;
using ll=long long;
ll work(set<int>&a,set<int>&b,int n,int m){
	int i,j,k;
	ll s=-1e18;
	mp.clear(),v.clear();
	for(int i:a)mp[i]=i;
	for(int i:b)if(mp.count(j=i%n))mp[j]=min(mp[j],i);else mp[j]=i;
	exgcd(n,m,i,j),j=(j+n)%n,i=mp.begin()->first;
	for(auto o:mp)v.push_back(make_tuple(j*1ll*(o.first-i)%n,o.second,a.count(o.first)));
	sort(v.begin(),v.end()),j=v.size(),v.push_back(make_tuple(n,0,0));
	for(i=0;i<j;++i)if(k=get<0>(v[i+1])-get<0>(v[i])-1,get<2>(v[i])==0||k>0)s=max(s,get<1>(v[i])+k*1ll*m);
	return s;
}
int main(){
	int n,m,d,i,j;
	ll p,s=0;
	if(in(n),in(m),(d=__gcd(n,m))>M)return puts("-1"),0;
	for(in(j);j--;)in(i),a[i%d].insert(i/d);
	for(in(j);j--;)in(i),b[i%d].insert(i/d);
	for(i=0,n/=d,m/=d;i<d;++i){
		if(a[i].empty()&&b[i].empty())return puts("-1"),0;
		p=work(a[i],b[i],n,m),p=max(p,work(b[i],a[i],m,n)),s=max(s,p*d+i);
	}
	printf("%lld",s);
	return 0;
}