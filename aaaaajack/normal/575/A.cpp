#include<cstdio>
#include<algorithm>
#include<ctime>
#define N 1<<16
using namespace std;
int P,n;
int tr[N<<1][2][2],v[N],id[N];
long long pos[N];
int s[N];
inline void ass(int a[][2],int b[][2]){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			a[i][j]=b[i][j];
		}
	}
}
void mul(int a[][2],int b[][2],int c[][2]){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			c[i][j]=0;
			for(int k=0;k<2;k++){
				c[i][j]+=1LL*a[i][k]*b[k][j]%P;
			}
			if(c[i][j]>=P) c[i][j]-=P;
		}
	}
}
void build(int u,int l,int r){
	if(r-l==1){
		tr[u][0][0]=s[l];
		tr[u][0][1]=s[(l+n-1)%n];
		tr[u][1][0]=1;
		tr[u][1][1]=0;
		return;
	}
	build(u<<1,l,(l+r)/2);
	build(u<<1|1,(l+r)/2,r);
	mul(tr[u<<1|1],tr[u<<1],tr[u]);
}
void qtr(int u,int l,int r,int ql,int qr,int res[][2]){
	if(ql>=qr){
		res[0][0]=res[1][1]=1;
		res[0][1]=res[1][0]=0;
		return;
	}
	if(l==ql&&r==qr){
		ass(res,tr[u]);
		return;
	}
	int m=(l+r)/2;
	if(ql>=m){
		qtr(u<<1|1,m,r,ql,qr,res);
	}
	else if(qr<=m){
		qtr(u<<1,l,m,ql,qr,res);
	}
	else{
		int ml[2][2],mr[2][2];
		qtr(u<<1,l,m,ql,m,ml);
		qtr(u<<1|1,m,r,m,qr,mr);
		mul(mr,ml,res);
	}
}
void qp(long long p,int res[2][2]){
	int x[2][2],y[2][2]={1,0,0,1};
	ass(res,y);
	ass(x,tr[1]);
	while(p){
		if(p&1){
			mul(res,x,y);
			ass(res,y);
		}
		mul(x,x,y);
		ass(x,y);
		p>>=1;
	}
}
void qry(long long l,long long r,int res[][2]){
	if(l>=r){
		res[0][0]=res[1][1]=1;
		res[0][1]=res[1][0]=0;
	}
	else if(l/n==r/n) qtr(1,0,n,l%n,r%n,res);
	else{
		int ml[2][2],mm[2][2],mr[2][2],tmp[2][2];
		qtr(1,0,n,l%n,n,ml);
		qtr(1,0,n,0,r%n,mr);
		qp(r/n-l/n-1,mm);
		mul(mm,ml,tmp);
		mul(mr,tmp,res);
	}
}
bool cmp(int i,int j){
	return pos[i]<pos[j];
}
int main(){
	int m,tres[2][2],res[2][2];
	long long k;
	scanf("%I64d%d",&k,&P);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&s[i]);
	build(1,0,n);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		id[i]=i;
		scanf("%I64d%d",&pos[i],&v[i]);
	}
	if(k==0){
		puts("0");
		return 0;
	}
	id[m]=m;
	pos[m]=k;
	sort(id,id+m+1,cmp);
	qry(1,pos[id[0]],res);
	for(int i=0;i<=m&&pos[id[i]]<k;i++){
		int tmp[2][2]={v[id[i]],i&&pos[id[i]]==pos[id[i-1]]+1?v[id[i-1]]:s[(pos[id[i]]+n-1)%n],1,0};
		mul(tmp,res,tres);
		ass(res,tres);
		if(pos[id[i]]+1<pos[id[i+1]]){
			tmp[0][0]=s[(pos[id[i]]+1)%n];
			tmp[0][1]=v[id[i]];
			mul(tmp,res,tres);
			ass(res,tres);
		}
		qry(pos[id[i]]+2,pos[id[i+1]],tmp);
		mul(tmp,res,tres);
		ass(res,tres);
	}
	printf("%d\n",res[0][0]%P);
	return 0;
}