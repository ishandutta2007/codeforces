#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+5;

bool cmp(int x,int y){
	return abs(x)<abs(y);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		static int a[N],b[N];
		a[0]=b[0]=0;
		for(int i=1,x,y;i<=2*n;++i){
			scanf("%d%d",&x,&y);
			if(!x)a[++a[0]]=y;
			else b[++b[0]]=x;
		}
		sort(a+1,a+a[0]+1,cmp);
		sort(b+1,b+b[0]+1,cmp);
		long double ans=0;
		for(int i=1;i<=n;++i)ans+=sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
		printf("%.12Lf\n",ans);
	}
}
/*
2 2
1 1
1 1 1 2
1 1 1 2
8 3
4 2 2 1 2 2 4 4
1 3 1 2
2 4 4
1 2 9 2

7 5
1 1 2 2 3 3 1
2 4 4
2 5 2
2 6 6
1 5 2 9
1 5 2 9
*/