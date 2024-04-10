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
int n;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int a[100100];
struct SegTree{
	int sum,suf;
}seg[400100];
void pushup(int x){
	seg[x].sum=seg[lson].sum+seg[rson].sum;
	seg[x].suf=max(seg[rson].suf,seg[lson].suf+seg[rson].sum);
}
void modify(int x,int l,int r,int P,int val){
	if(l==r)seg[x].sum=seg[x].suf=val;else P<=mid?modify(lson,l,mid,P,val):modify(rson,mid+1,r,P,val),pushup(x);
}
int query(int x,int l,int r,int sum){
	if(seg[x].suf+sum<=0)return -1;
	if(l==r)return a[l];
	int ret=query(rson,mid+1,r,sum);
	if(ret!=-1)return ret;
	return query(lson,l,mid,sum+seg[rson].sum);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,z;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(!y)modify(1,1,n,x,-1);
		else modify(1,1,n,x,1),scanf("%d",&a[x]);
		printf("%d\n",query(1,1,n,0));
	}
	return 0;
}