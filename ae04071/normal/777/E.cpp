#include <stdio.h>
#include <algorithm>
#include <utility>

using ip=std::pair<int, int>;
using lli=long long;

struct data {
	int a,b,h;
};
struct d2 {
	int num, idx, ord;
};

int n;
data arr[100000];
lli tree[1<<20];

d2 tmp[200001];

bool cmp(const data &a, const data &b) {
	if(a.b!=b.b) return a.b>b.b;
	else return a.a>b.a;	
}
bool cmp_d2(const d2 &a, const d2 &b) {
	return a.num<b.num;
}

lli Update(int node ,int st, int fi, int idx, lli val) {
	if(fi<idx||st>idx) return tree[node];
	else if(st==idx&&fi==idx) return tree[node]=std::max(tree[node],val);
	else return tree[node]=std::max(Update(node*2,st,(st+fi)/2,idx,val),Update(node*2+1,(st+fi)/2+1,fi,idx,val));
}
lli Max(int node, int st, int fi, int le, int ri ){
	if(le>ri) return 0;
	if(fi<le||st>ri) return 0;
	else if(le<=st&&fi<=ri) return tree[node];
	else return std::max(Max(node*2,st,(st+fi)/2,le,ri),Max(node*2+1,(st+fi)/2+1,fi,le,ri));
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].h);
		tmp[i*2].num=arr[i].a; tmp[i*2].idx=i; tmp[i*2].ord=0;
		tmp[i*2+1].num=arr[i].b; tmp[i*2+1].idx=i; tmp[i*2+1].ord=1;
	}

	int num=0;
	std::sort(tmp, tmp+n*2,cmp_d2);
	for(int i=0;i<n*2;i++) {
		int tt;
		if(i!=0 && tmp[i].num==tmp[i-1].num) 
			tt=num-1;
		else
			tt=num++;

		if(tmp[i].ord==0) {
			arr[tmp[i].idx].a=tt;
		}
		else
			arr[tmp[i].idx].b=tt;
	}

	long long max=0;
	std::sort(arr, arr+n, cmp);
	for(int i=0;i<n;i++) {
		lli th=Max(1,0,num-1, 0, arr[i].b-1);
		th+=(long long)arr[i].h;
		if(max<th) max=th;
		Update(1,0,num-1, arr[i].a, th);
	}
	printf("%lld\n",max);
	return 0;
}