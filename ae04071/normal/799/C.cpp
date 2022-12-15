#include <cstdio>
#include <algorithm>
#include <utility>

const int MAX=100000;
typedef std::pair<int, int> ip;
ip cf[MAX],df[MAX];
int m[MAX];
int n,c,d,cn,dn;

bool cmp_sec(const ip &a, const ip &b) {
	return (a.second!=b.second)?a.second<b.second:a.first<b.first;
}
int mb(ip *arr,int n,int cost) {
	if(n<=1) return 0;
	std::sort(arr,arr+n,cmp_sec);
	m[0]=arr[0].first;
	for(int i=1;i<n;i++) m[i]=std::max(m[i-1],arr[i].first);
	int max=0;
	for(int i=n-1;i>0;i--) {
		int lo=0,up=i;
		while(up-lo>1) {
			int md=(lo+up)/2;
			if(arr[i].second+arr[md].second<=cost) lo=md;
			else up=md;
		}
		if(arr[i].second+arr[lo].second<=cost) {
			max=std::max(max,arr[i].first+m[lo]);
		}
	}
	return max;
}
int main() {
	int a,b;
	char ch;
	scanf("%d",&n);
	scanf("%d %d",&c,&d);
	for(int i=0;i<n;i++) {
		scanf("%d %d %c", &a,&b,&ch);
		if(ch=='C') cf[cn++]=ip(a,b);
		else df[dn++]=ip(a,b);
	}
	int max=0;
	max=std::max(max,mb(cf,cn,c));
	max=std::max(max,mb(df,dn,d));
	int m1=0,m2=0;
	for(int i=0;i<cn;i++) if(cf[i].second<=c) m1=std::max(m1,cf[i].first);
	for(int i=0;i<dn;i++) if(df[i].second<=d) m2=std::max(m2,df[i].first);
	if(m1!=0 && m2!=0) max=std::max(max,m1+m2);
	printf("%d\n",max);
	return 0;
}