#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 2001000
using namespace std;
struct diff{
	char a[20];
	int lm,lw,sum;
	bool operator<(const diff& rhs)const{return lm<rhs.lm||lm==rhs.lm&&lw<rhs.lw||lm==rhs.lm&&lw==rhs.lw&&sum>rhs.sum;}
}left[N],right[N];
int x[20],y[20],z[20];
char pa[20];
void build(int n,int now,diff left[],int &cnt,int plm,int plw,int psum){
	if(now==n){
		left[cnt].lm=plm;
		left[cnt].lw=plw;
		left[cnt].sum=psum;
		memcpy(left[cnt].a,pa,sizeof(pa));
		cnt++;
		return;
	}
	pa[now]=0;
	build(n,now+1,left,cnt,plm+x[now]-y[now],plw+x[now],psum+x[now]+y[now]);
	pa[now]=1;
	build(n,now+1,left,cnt,plm+x[now],plw+x[now]-z[now],psum+x[now]+z[now]);
	pa[now]=2;
	build(n,now+1,left,cnt,plm-y[now],plw-z[now],psum+y[now]+z[now]);
}
int main(){
	char s[3][100]={"LM","LW","MW"};
	int n,lcnt=0,rcnt=0,ansi=-1,ansj=-1,anssum;
	scanf("%d",&n);
	for(int i=0;i<n/2;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	build(n/2,0,left,lcnt,0,0,0);
	for(int i=n/2;i<n;i++){
		scanf("%d%d%d",&x[i-n/2],&y[i-n/2],&z[i-n/2]);
	}
	build(n-n/2,0,right,rcnt,0,0,0);
	sort(left,left+lcnt);
	sort(right,right+rcnt);
	for(int i=0,j=rcnt-1;i<lcnt&&j>=0;i++){
		while(j>=0&&left[i].lm>-right[j].lm) j--;
		while(j>=0&&left[i].lm==-right[j].lm&&left[i].lw>-right[j].lw) j--;
		while(j>=0&&left[i].lm==-right[j].lm&&left[i].lw==-right[j].lw){
			if(ansi==-1||left[i].sum+right[j].sum>anssum){
				ansi=i;
				ansj=j;
				anssum=left[i].sum+right[j].sum;
			}
			j--;
		}
	}
	if(ansi==-1) puts("Impossible");
	else{
		for(int i=0;i<n/2;i++){
			puts(s[left[ansi].a[i]]);
		}
		for(int i=n/2;i<n;i++){
			puts(s[right[ansj].a[i-n/2]]);
		}
	}
	return 0;
}