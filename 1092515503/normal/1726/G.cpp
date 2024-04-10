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
const int mod=998244353;
int n,a[200100],b[200100],res=1,C;
vector<int>sml,lar;
int fac[200100];
bool allsame(){
	bool as=true;
	for(int i=2;i<=n;i++)as&=(a[i]==a[1]);
	if(!as)return false;
	printf("%d\n",fac[n]);
	return true;
}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct SegTree{int sum,mn;}seg[3001000];
void pushup(int x){
	seg[x].mn=min(seg[lson].mn-seg[rson].sum,seg[rson].mn);
	seg[x].sum=seg[lson].sum+seg[rson].sum;
}
void turn(int x,int l,int r,int P,bool tp){
	if(l==r)seg[x].mn=(tp?C-P:0x3f3f3f3f);
	else P<=mid?turn(lson,l,mid,P,tp):turn(rson,mid+1,r,P,tp),pushup(x);
}
void modify(int x,int l,int r,int P,int del){
	if(l==r)seg[x].sum+=del;
	else P<=mid?modify(lson,l,mid,P,del):modify(rson,mid+1,r,P,del),pushup(x);
}
int query(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0;
	if(L<=l&&r<=R)return seg[x].sum;
	return query(lson,l,mid,L,R)+query(rson,mid+1,r,L,R);
}
int getpos(int x,int l,int r,int del=0){
	if(l==r)return r;
	if(seg[rson].mn==del)return getpos(rson,mid+1,r,del);
	return getpos(lson,l,mid,del+seg[rson].sum);
}
int main(){
	scanf("%d",&n);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	if(allsame())return 0;
	for(int i=1;i<=n;i++)
		if(!b[i])sml.push_back(a[i]);
		else lar.push_back(a[i]);
	sort(sml.begin(),sml.end());
	sort(lar.begin(),lar.end());
	if(lar.empty()){puts("0");return 0;}
	if(!sml.empty()&&sml[0]<=lar[0]){puts("0");return 0;}
	C=lar[0]+n-1;
	if(*max_element(a+1,a+n+1)>C){puts("0");return 0;}
	for(int i=1;i<=C;i++)turn(1,1,C,i,false);
	for(auto x:sml)modify(1,1,C,x,1);
	for(auto x:lar)modify(1,1,C,x,1),turn(1,1,C,x,true);
	turn(1,1,C,C,false);
	int ext=0;
	while(!lar.empty()&&lar.back()==C)lar.pop_back(),ext++;
	if(unique(lar.begin(),lar.end())!=lar.end()){puts("0");return 0;}
	// for(auto x:sml)printf("%d ",x);puts("");
	// for(auto x:lar)printf("%d ",x);puts("");
	for(int l=0,r=0;l<sml.size();l=r+1){
		for(r=l;r+1<sml.size()&&sml[r+1]==sml[l];r++);
		res=1ll*res*fac[r-l+1]%mod;
	}
	for(int i=n-ext+1;i<=n;i++)res=1ll*res*i%mod;
	for(int i=0,j=0;i<sml.size()||j<lar.size();){
		if(seg[1].mn<0){puts("0");return 0;}
		int a=-1,b=-1;
		if(i<sml.size()&&sml[i]+query(1,1,C,1,sml[i]-1)==C)
			a=sml[i];
		if(!seg[1].mn)b=getpos(1,1,C);
		if(a==-1&&b==-1){puts("0");return 0;}
		if(a!=-1&&(b==-1||a>b))
			modify(1,1,C,a,-1),modify(1,1,C,C,1),i++;
		else
			modify(1,1,C,b,-1),modify(1,1,C,C,1),turn(1,1,C,b,false),j++;
	}
	printf("%d\n",res);
	return 0;
}