#include<bits/stdc++.h>
#define N 110
using namespace std;
int c[N][26];
char ans[N];
int cnt;
bitset<N> a[N*3];
int b[N*3];
void solve(int l, int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int n=r-l+1;
	string s;
	memset(c,0,sizeof(c));
	for(int i=0;i<n*(n+1)/2;i++){
		cin>>s;
		for(int j=0;j<s.size();j++){
			c[s.size()][s[j]-'a']++;
		}
	}
	int pre[26]={};
	for(int i=0;i<26;i++) pre[i]=c[1][i];
	for(int k=0;l+k<r-k;k++){
		a[cnt][l+k]=1;
		a[cnt][r-k]=1;
		int tmp[26]={};
		for(int i=0;i<26;i++){
			tmp[i]+=c[k+2][i]-c[k+1][i];
		}
		bool flag=false;
		/*for(int i=0;i<26;i++){
			if(pre[i]-tmp[i]>=2){
				flag=true;
				b[cnt]=i;
				b[cnt+1]=i;
				a[cnt+1][r-k]=1;
				a[cnt][r-k]=0;
				cnt+=2;
				break;
			}
		}*/
		for(int i=0;i<26;i++){
			for(int j=0;j<pre[i]-tmp[i];j++){
				b[cnt]^=i;
			}
		}
		cnt++;
		for(int i=0;i<26;i++) pre[i]=tmp[i];
	}
	if(n&1){
		for(int i=0;i<26;i++){
			if(pre[i]){
				a[cnt][(l+r)/2]=1;
				b[cnt]=i;
				cnt++;
				break;
			}
		}
	}
}
void Gaussian(int n){
	int piv=-1;
	for(int i=0;i<cnt;i++){
		piv=-1;
		for(int j=1;j<=n;j++){
			if(a[i][j]){
				piv=j;
				break;
			}
		}
		if(piv==-1) continue;
		for(int j=i+1;j<cnt;j++){
			if(a[j][piv]){
				a[j]^=a[i];
				b[j]^=b[i];
			}
		}
	}
	for(int i=cnt-1;i>=0;i--){
		piv=-1;
		for(int j=1;j<=n;j++){
			if(a[i][j]){
				piv=j;
				break;
			}
		}
		if(piv==-1) continue;
		ans[piv]='a'+b[i];
		for(int j=0;j<i;j++){
			if(a[j][piv]){
				a[j]^=a[i];
				b[j]^=b[i];
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	solve(1,n);
	if(n>1){
		/*int l=n/2;
		if(n%4==0||n%4==1) l--; 
		if(n%4==2&&n>2) l-=2;
		solve(1,l);
		solve(l+1,n);*/
		solve(1,n-1);
	}
	Gaussian(n);
	printf("! %s\n",ans+1);
	return 0;
}