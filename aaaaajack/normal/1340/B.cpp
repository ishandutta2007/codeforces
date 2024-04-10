/* in the name of Anton */
#include<bits/stdc++.h>
#define N 2010
#define all(x) begin(x),end(x)
using namespace std;
bitset<7> a[N],d[N];
char dig[10][10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int good[N][N];
char s[10];
int solve(int i,int n,int k){
	if(i==n){
		if(k==0) return 0;
		else return -2;
	}
	if(good[i][k]!=-1) return good[i][k];
	for(int j=9;j>=0;j--){
		if((a[i]&d[j])==a[i]){
			int nw=(d[j]^a[i]).count();
			if(nw<=k && solve(i+1,n,k-nw)>=0) return good[i][k]=j;
		}
	}
	return good[i][k]=-2;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		a[i]=bitset<7>(s);
	}
	memset(good,-1,sizeof(good));
	for(int i=0;i<10;i++) d[i]=bitset<7>(dig[i]);
	if(solve(0,n,k)>=0){
		for(int i=0;i<n;i++){
			printf("%d",good[i][k]);
			k-=(d[good[i][k]]^a[i]).count();
		}
	}
	else{
		puts("-1");
	}
	return 0;
}