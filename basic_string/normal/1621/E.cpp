#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
using ll=long long;
using db=double;
struct G{
	vector<int>v;
	int sz,id;
	long long sum;
	double a;
}g[N];
int a[N],rk[N];
double a2[N];
set<int>sa,sb,sc;
bool chk(set<int>&st,int l,int r){
	auto o=st.lower_bound(l);
	if(o==st.end()||*o>r)return 1;
	return 0;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,x,y,z;
	for(cin>>T;T--;){
		 cin>>n>>m;
		for(i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1,greater<int>());
		for(i=1;i<=m;++i){
			cin>>g[i].sz,g[i].id=i;g[i].sum=0;g[i].v.clear();
			for(j=1;j<=g[i].sz;++j)cin>>k,g[i].v.push_back(k),g[i].sum+=k;
			g[i].a=g[i].sum*1./g[i].sz;
		}
		sort(g+1,g+m+1,[](G x,G y){return x.a>y.a;});
		for(i=1;i<=m;++i)rk[g[i].id]=i,a2[i]=g[i].a;
		sa=sb=sc={};
		for(i=1;i<=m;++i)if(g[i].a-1e-8>a[i])sb.insert(i);
		for(i=1;i<m;++i){
		if(g[i+1].a-1e-8>a[i])sa.insert(i+1);
		if(g[i].a-1e-8>a[i+1])sc.insert(i);
		}
		for(x=1;x<=m;++x){
			i=rk[x];
			if(g[i].sz>1){
				for(auto o:g[i].v){
				double now=(g[i].sum-o)*1./(g[i].sz-1);
				j=lower_bound(a2+1,a2+m+1,now+1e-8,greater<double>())-a2;
				if(j>i)--j;
				if(i<j){
					if(chk(sb,1,i-1)&&chk(sa,i+1,j)&&chk(sb,j+1,n)
					&&now-1e-8<a[j])cout<<1;else cout<<0;
				}else if(i>j){
					if(chk(sb,1,j-1)&&chk(sc,j,i-1)&&chk(sb,i+1,n)
					&&now-1e-8<a[j])cout<<1;else cout<<0;
				}else{
					if(chk(sb,1,i-1)&&chk(sb,i+1,n)&&now-1e-8<a[j]){
						cout<<1;
					} else cout<<0;
				}
				}
			}else{
				if(chk(sb,1,i-1)&&chk(sa,i+1,n))cout<<1;
				else cout<<0;
			}
		}
		cout<<'\n';
	}
	return 0;
}