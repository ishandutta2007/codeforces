#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
const int BL = 30;

int n,m;
vector<int> a[N];

int get(int x,int &y){
	int mx=0;
	for(int i=0;i<n;++i)
	if(i!=x){
		int now=0;
		for(int j=0;j<m;++j)now+=a[i][j]!=a[x][j];
		if(now>mx){
			mx=now;
			y=i;
		}
	}
	return mx;
}

void out(int *x){
	for(int i=0;i<m;++i)printf("%d ",x[i]);
	printf("\n");
}

bool check(int *x){
	for(int i=0;i<n;++i){
		int cnt=0;
		for(int j=0;j<m;++j)cnt+=a[i][j]!=x[j];
		if(cnt>2)return 0;
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		a[i].resize(m);
		for(int j=0;j<m;++j){
			scanf("%d",&a[i][j]);
		}
	}
	int dif=0;
	int x=1,y;
	for(int i=1;i<=BL;++i){
		dif=get(x,y);
		if(dif<=2||i==BL)break;
		x=y;
	}
	static int q[N];
	for(int j=0;j<m;++j)
	if(a[x][j]!=a[y][j]){
		q[++q[0]]=j;
	}
	assert(q[0]==dif);
	if(dif>4){
		puts("No");
	}
	else if(dif==4){
		static int p[5],ans[N];
		for(int i=1;i<=4;++i)p[i]=i;
		do{
			for(int j=0;j<m;++j)ans[j]=a[x][j];
			ans[q[p[1]]]=a[y][q[p[1]]];
			ans[q[p[2]]]=a[y][q[p[2]]];
			if(check(ans)){
				puts("Yes");
				out(ans);
				return 0;
			}
		}while(next_permutation(p+1,p+5));
		puts("No");
	}
	else if(dif==3){
		for(int i=1;i<=3;++i)
		for(int t=1;t<=3;++t)
		if(i!=t){
			static int ans[N];
			int k=q[6-i-t];
			for(int j=0;j<m;++j)ans[j]=a[x][j];
			ans[q[i]]=a[x][q[i]];
			ans[q[t]]=a[y][q[t]];
			bool flag=0;
			int sp=0;
			for(int i1=0;i1<n;++i1){
				int cnt=0;
				for(int j1=0;j1<m;++j1)
				if(j1!=k){
					cnt+=a[i1][j1]!=ans[j1];
				}
				if(cnt>2)flag=1;
				if(cnt==2){
					if(!sp)sp=a[i1][k];
					else{
						if(sp!=a[i1][k]){
							flag=1;
						}
					}
				}
			}
			if(flag)continue;
			ans[k]=max(sp,1);
			if(check(ans)){
				puts("Yes");
				out(ans);
				return 0;
			}
		}
		puts("No");
	}
	else{
		puts("Yes");
		for(int i=0;i<m;++i){
			printf("%d ",a[x][i]);
		}
		printf("\n");
	}
}