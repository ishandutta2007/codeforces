#include<cstdio>
#include<cstring>
#include<vector>
#define K 40
#define Q 1000000007
using namespace std;
struct matrix{
	long long e[K][K];
	static int sz;
	matrix(bool iden=false){
		memset(e,0,sizeof(e));
		int i;
		if(iden){
			for(i=0;i<sz;i++) e[i][i]=1;
		}
	}
	matrix operator*(const matrix& rhs)const{
		matrix r;
		int i,j,k;
		for(i=0;i<sz;i++){
			for(j=0;j<sz;j++){
				for(k=0;k<sz;k++){
					r.e[i][j]+=e[i][k]*rhs.e[k][j];
					r.e[i][j]%=Q;
				}
			}
		}
		return r;
	}
	vector<long long> operator*(const vector<long long>& v)const{
		int i,j;
		vector<long long> ret(sz,0);
		for(i=0;i<sz;i++){
			for(j=0;j<sz;j++){
				ret[i]+=e[i][j]*v[j];
				ret[i]%=Q;
			}
		}
		return ret;
	}
	matrix shift(int r)const{
		matrix tmp;
		int i,j;
		for(i=0;i<sz;i++){
			for(j=0;j<sz;j++){
				tmp.e[i==sz-1?sz-1:(i+r)%(sz-1)][j==sz-1?sz-1:(j+r)%(sz-1)]=e[i][j];
			}
		}
		return tmp;
	}
	void print()const{
		int i,j;
		for(i=0;i<sz;i++){
			for(j=0;j<sz;j++){
				printf("%d ",e[i][j]);
			}
			putchar('\n');
		}
	}
}A[100];
int matrix::sz;
int main(){
	long long n,r=1,sum=0;
	int k,i,j,w,up=0,os;
	matrix B;
	scanf("%I64d%d",&n,&k);
	matrix::sz=k+1;
	vector<long long> ans(k+1,0);
	ans[k]=1;
	for(i=0;i<k+1;i++){
		A[0].e[0][i]=A[0].e[i][i]=1;
	}
	while(n/r>=k){	
		r*=k;
		up++;
	}
	for(i=1;i<=up;i++){
		B=A[i-1];
		A[i]=matrix(true);
		j=k;
		w=0;
		while(j){
			if(j&1){
				A[i]=A[i]*B.shift((j^1)<<w);
			}
			B=B.shift(1<<w)*B;
			w++;
			j>>=1;
		}
	}
	os=0;
	while(n){
		for(i=0;i<n/r;i++){
			ans=A[up].shift(os+i)*ans;
		}
		os=(os+i)%k;
		n%=r;
		r/=k;
		up--;
	}
	for(i=0;i<k+1;i++){
		sum=(sum+ans[i])%Q;
	}
	printf("%I64d\n",sum);
	return 0;
}