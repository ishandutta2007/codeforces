#include<bits/stdc++.h>
using namespace std;
pair<int,int>dat[2097152];
int a[500003];
void upd(int k,int l,int r,int R,int L){
	if(l==r){
		dat[k]=make_pair(L,a[l]);
		return ;
	}
	if(R<=(l+r)/2)
		upd(k*2,l,(l+r)/2,R,L);
	else
		upd(k*2+1,(l+r+1)/2,r,R,L);
	dat[k]=max(dat[k*2],dat[k*2+1]);
}
pair<int,int>query(int k,int l,int r,int a,int b){
	if(a>b)return make_pair(0,0);
	if(a<=l&&r<=b)return dat[k];
	return max(query(k*2,l,(l+r)/2,a,min((l+r)/2,b)),query(k*2+1,(l+r+1)/2,r,max((l+r+1)/2,a),b));
}
int n,lst[500003],l[500003],r[500003],ans[500003];
vector<pair<pair<int,int>,int> >v,q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]--,l[i]=lst[a[i]],lst[a[i]]=i;
	for(int i=0;i<500000;i++)
		lst[i]=n+1;
	for(int i=n;i>0;i--)r[i]=lst[a[i]],lst[a[i]]=i;
	for(int i=1;i<=n;i++)
		v.push_back(make_pair(make_pair(l[i],r[i]),i));
	sort(v.begin(),v.end());
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int ll,rr;
		scanf("%d%d",&ll,&rr);
		q.push_back(make_pair(make_pair(ll,rr),i));
	}
	sort(q.begin(),q.end());
	int nw=0;
	for(int i=0;i<T;i++){
		int l=q[i].first.first,r=q[i].first.second,idx=q[i].second;
		while(nw<v.size()&&v[nw].first.first<l)
			upd(1,1,n,v[nw].second,v[nw].first.second),nw++;
		pair<int,int>res=query(1,1,n,l,r);
		if(res.first>r)
			ans[idx]=res.second+1;
	}
	for(int i=1;i<=T;i++)
		printf("%d\n",ans[i]);
}