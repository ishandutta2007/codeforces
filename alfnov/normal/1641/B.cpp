#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g;
vector<int>gg;
/*
int d[505][505];
int f[505][505];
int p1[505][505],p2[505][505];
void fpp(int l,int r,int py){
	if(r==l+1){
		g.emplace_back(make_pair(py+l,a[l]));
		return;
	}
	if(a[l]==a[r]&&d[l+1][r-1]){
		g.emplace_back(make_pair(py+l,a[l]));
		fpp(l+1,r-1,py);
		return;
	}
	for(int k=l+1;k<r;k+=2){
		if(d[l][k]&&d[k+1][r]){
			fpp(l,k,py);
			fpp(k+1,r,py);
			return;
		}
	}
}*/
int main(){
	int T;
	cin>>T;
	while(T--){
		g.clear(),gg.clear();
		int n;
		cin>>n;
		vector<int>a;
		for(int i=1;i<=n;++i){
			int aa;
			scanf("%d",&aa);
			a.emplace_back(aa);
		}
		if(n&1){
			puts("-1");
			continue;
		}/*
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
			d[i][j]=0;
		for(int i=1;i<=n;++i)d[i+1][i]=1;
		for(int l=2;l<=n;l+=2)for(int i=1;i<=n-l+1;++i){
			int j=i+l-1;
			if(a[i]==a[j]&&d[i+1][j-1]){
				d[i][j]=1;
				continue;
			}
			for(int k=i+1;k<j;k+=2)if(d[i][k]&&d[k+1][j]){
				d[i][j]=1;
				break;
			}
		}
		int flag=0;
		for(int m=0;m<=n;++m){
			for(int i=1;i<=m+1;++i)for(int j=m+1;j<=n+1;++j)
				f[i][j]=0,p1[i][j]=p2[i][j]=-1;
			f[m+1][n+1]=1,p1[m+1][n+1]=p2[m+1][n+1]=0;
			for(int i=m+1;i>=1;--i)for(int j=n+1;j>=m+1;--j){
				if(i==m+1&&j==n+1)continue;
				if(i<=m&&j<=n&&a[i]==a[j]&&f[i+1][j+1]){
					f[i][j]=1;
					p1[i][j]=i+1,p2[i][j]=j+1;
					continue;
				}
				int ff=0;
				for(int k=j+1;k<=n;++k){
					if(d[j][k]&&f[i][k+1]){
						f[i][j]=1;
						p1[i][j]=i,p2[i][j]=k+1;
						ff=1;
						break;
					}
				}
				if(ff)continue;
				for(int k=i+1;k<=m;++k){
					if(d[i][k]&&f[k+1][j]){
						f[i][j]=1;
						p1[i][j]=k+1,p2[i][j]=j;
						ff=1;
						break;
					}
				}
				if(ff)continue;
				f[i][j]=0;
			}
			if(f[1][m+1]){
				int A=0,B=0;
				int I=1,J=m+1;
				while(I<=m||J<=n){
					int w1=p1[I][J],w2=p2[I][J];
					if(w1>I&&w2>J){
						++A,++B;
						I=w1,J=w2;
						continue;
					}
					if(w1==I){
						fpp(J,w2-1,A-J);
						A+=w2-J,B+=w2-J;
					}else{
						fpp(I,w1-1,m-I+1+A+B-I);
						B+=w1-I,A+=w1-I;
					}
					I=w1,J=w2;
				}
				printf("%d\n",(signed)g.size());
				for(auto cu:g)printf("%d %d\n",cu.first,cu.second);
				printf("1\n");
				printf("%d\n",A+B);
				flag=1;
				break;
			}
		}
		if(!flag)puts("-1");*/
		int flag=1;
		for(int i=0;i<a.size();){
			int wz=-1;
			for(int j=i+1;j<a.size();++j)if(a[i]==a[j]){
				wz=j;
				break;
			}
			if(wz==-1){
				flag=0;
				break;
			}
			for(int j=i+1;j<wz;++j){
				g.emplace_back(make_pair(wz+(j-i),a[j]));
				a.insert(a.begin()+wz+(j-i),a[j]);
				a.insert(a.begin()+wz+(j-i),a[j]);
			}
			int fx=wz+(wz-i-1);
			gg.emplace_back(fx-i+1);
			i=fx+1;
		}
		if(!flag)puts("-1");
		else{
			printf("%d\n",(signed)g.size());
			for(auto cu:g)printf("%d %d\n",cu.first,cu.second);
			printf("%d\n",(signed)gg.size());
			for(auto cu:gg)printf("%d ",cu);
			printf("\n");
		}
	}
	return 0;
}