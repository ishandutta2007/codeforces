#include<bits/stdc++.h>
using namespace std;
const int BBB=100;
int n,m,q,BLK[200100],lp[2010];
int a[200100];
int f[2][2010][12];//1-m+1:the first block that fails is i;
bool rev[2010];
int tmp[200100];
void rebuild(int ip){
	for(int i=1;i<=m+1;i++){
		f[0][ip][i]=i;
		for(int j=lp[ip+1]-1;j>=lp[ip];j--){
			if(!a[j]||f[0][ip][i]<=m)f[0][ip][i]++;
			else f[0][ip][i]=1;
		}
		f[0][ip][i]=min(f[0][ip][i],m+1);
		f[1][ip][i]=i;
		for(int j=lp[ip+1]-1;j>=lp[ip];j--){
			if(a[j]||f[1][ip][i]<=m)f[1][ip][i]++;
			else f[1][ip][i]=1;
		}
		f[1][ip][i]=min(f[1][ip][i],m+1);
	}
}
void read(int&x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
int main(){
	read(n),read(m),read(q);
	for(int i=0;i<n;i++)read(a[i]),a[i]&=1,BLK[i]=i/BBB;
	lp[BLK[n]=BLK[n-1]+1]=n;
	for(int i=0;i<BLK[n];i++)lp[i]=i*BBB;
	for(int i=0;i<BLK[n];i++)rebuild(i); 
	for(int i=1,tp,l,r,x;i<=q;i++){
		read(tp),read(l),read(r),l--,r--;
		if(tp==1){
			read(x),x&=1;
			if(!x)continue;
//			printf("TURN[%d,%d]\n",l,r);
			if(BLK[l]==BLK[r]){for(int j=l;j<=r;j++)a[j]^=1;rebuild(BLK[l]);continue;}
			for(int j=BLK[l]+1;j<=BLK[r]-1;j++)rev[j]^=1;
			for(int j=l;j<lp[BLK[l]+1];j++)a[j]^=1;rebuild(BLK[l]);
			for(int j=lp[BLK[r]];j<=r;j++)a[j]^=1;rebuild(BLK[r]);
		}else{
//			printf("ASK[%d,%d]\n",l,r);
			int fail=m+1;
			if(BLK[l]==BLK[r]){
				for(int j=r;j>=l;j--){
					if(!(a[j]^rev[BLK[r]])||fail<=m)fail++;
					else fail=1;
				}
				putchar(fail==1?'2':'1'),putchar('\n');
				continue;
			}
//			puts("IN");
			for(int j=r;j>=lp[BLK[r]];j--){
				if(!(a[j]^rev[BLK[r]])||fail<=m)fail++;
				else fail=1;
			}
			fail=min(fail,m+1);
			for(int j=BLK[r]-1;j>=BLK[l]+1;j--)fail=f[rev[j]][j][fail];
			for(int j=lp[BLK[l]+1]-1;j>=l;j--){
				if(!(a[j]^rev[BLK[l]])||fail<=m)fail++;
				else fail=1;
			}
			fail=min(fail,m+1);
			putchar(fail==1?'2':'1'),putchar('\n');
		}
	}
	return 0;
}
/*
5 2 4
1 2 3 4 5
1 3 5 6
2 2 5
1 1 2 3
2 1 5
*/