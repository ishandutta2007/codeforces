#include<cstdio>
#include<algorithm>
using namespace std;
struct pack{
	int num;
	int r;
};
bool cmp_n(const pack& a,const pack& b){
	return a.num<b.num;
}
bool cmp_r(const pack& a,const pack& b){
	return a.r<b.r;
}
pack a[300010];
int main(){
	int n,i,now;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i].r);
		a[i].num=i;
	}
	sort(a,a+n,cmp_r);
	now=a[0].r;
	for(i=0;i<n;i++){
		if(a[i].r>now) now=a[i].r;
		else a[i].r=now;
		now++;
	}
	sort(a,a+n,cmp_n);
	for(i=0;i<n-1;i++){
		printf("%d ",a[i].r);
	}
	printf("%d\n",a[n-1].r);
	return 0;
}