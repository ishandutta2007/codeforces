#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int phi=998244352;
int n,m,A;
struct Matrix{
	int a[110][110];
	Matrix(){memset(a,0,sizeof(a));}
	int*operator[](const int&x){return a[x];}
	friend Matrix operator*(Matrix&u,Matrix&v){
		Matrix w;
		for(int i=1;i<=A;i++)for(int j=1;j<=A;j++)for(int k=1;k<=A;k++)(w[i][j]+=1ll*u[i][k]*v[k][j]%phi)%=phi;
		return w;
	}
	void print()const{for(int i=1;i<=A;i++){for(int j=1;j<=A;j++)printf("%d ",a[i][j]);puts("");}}
}M;
int ksm(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int KSM(){
	Matrix I;
	for(int i=1;i<=A;i++)I[i][i]=1;
	for(int y=n-A;y;y>>=1,M=M*M)if(y&1)I=I*M;
	return I[A][A];
}
unordered_map<int,int>mp;
int BSGS(int a,int b){
	if(b==0)return 1;
	mp.clear();
	int K=sqrt(mod);
	int P=1;
	for(int i=0;i<K;i++,P=1ll*P*a%mod)mp[1ll*P*b%mod]=i;
	for(int i=1,j=P;i<=K+2;i++,j=1ll*j*P%mod)if(mp.find(j)!=mp.end())return i*K-mp[j];
	return -1;
}
int main(){
	scanf("%d",&A);
	for(int i=1;i<=A;i++)scanf("%d",&M[A-i+1][A]);
	for(int i=2;i<=A;i++)M[i][i-1]=1;
//	M.print();
	scanf("%d%d",&n,&m);
	int a=KSM();
	int c=BSGS(ksm(3,a),m);
	if(c==-1){puts("-1");return 0;}
	int K=__gcd(a,phi),R=phi/K;
	if(K<=1048576){
		int res=mod;
		for(int i=0,j=ksm(3,c),k=ksm(3,R);i<K;i++,j=1ll*j*k%mod)res=min(res,j);
		printf("%d\n",res);
	}else for(int i=1;;i++)if(BSGS(3,i)%R==c%R){printf("%d\n",i);return 0;}
	return 0;
}