#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 222222;
int n,q,sz,p[N],a[N],b[N],c[N];
vector<int> v;
LL f[N],sa[N],sf[N],t[N];
set<int> S;
set<int>::iterator it;
int qx[N],ql[N],qr[N],qt[N];
vector<pair<int,int> > h[N];
LL ans[N];
void ad(int x,LL y){
	while(x<=n+1){
		t[x]+=y;
		x+=x&-x;
	}
}
LL qu(int x){
	LL y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y;
}
int main(){
	int i,j,k,o;
	LL x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",p+i);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		scanf("%d",b+i);
	p[0]=n+1;
	p[n+1]=n+1;
	v.push_back(0);
	sz=0;
	for(i=1;i<=n+1;i++){
		while(p[v[sz]]<p[i]){
			c[v[sz]]=i;
			v.pop_back();
			sz--;
		}
		v.push_back(i);
		sz++;
	}
	for(i=n;i>=1;i--){
		sa[i]=sa[i+1]+a[i];
		x=sa[i]-sa[c[i]]-b[i];
		y=sf[i+1]-sf[c[i]];
		if(x>y)
			f[i]=x-y;
		else
			f[i]=0;
		sf[i]=sf[i+1]+f[i];
	}
	S.insert(0);
	S.insert(n+1);
	h[0].push_back(make_pair(n+1,0));
	for(i=1;i<=q;i++){
		scanf("%d",qx+i);
		if(S.find(qx[i])==S.end()){
			qt[i]=1;
			it=S.lower_bound(qx[i]);
			qr[i]=*it;
			it--;
			ql[i]=*it;
			S.insert(qx[i]);
		}
		else{
			qt[i]=-1;
			S.erase(qx[i]);
			it=S.lower_bound(qx[i]);
			qr[i]=*it;
			it--;
			ql[i]=*it;
		}//cout<<ql[i]<<qx[i]<<qr[i]<<endl;
		h[ql[i]].push_back(make_pair(qx[i],i));
		h[qx[i]].push_back(make_pair(qr[i],i));
		h[ql[i]].push_back(make_pair(qr[i],-i));
	}
	for(i=n;i>=0;i--){
		if(i>0)
			ad(c[i],f[i]);
		for(j=0;j<h[i].size();j++){
			k=h[i][j].first;
			o=h[i][j].second;
			if(o>=0)
				ans[o]+=qu(k);
			else
				ans[-o]-=qu(k);
		}
	}
	x=ans[0];
	for(i=1;i<=q;i++){
		x+=ans[i]*qt[i];
		cout<<sa[1]-x<<endl;
	}
	return 0;
}