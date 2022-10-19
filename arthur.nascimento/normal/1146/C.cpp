#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300300
#define bs bitset<maxn>
#define debug
#define pb push_back
#define pii pair<int,int>
char str[maxn];
char s2[maxn];

int get(int x,int a,int b){
	printf("%d %d ",1,b-a+1);
	printf("%d ",x+1);
	for(int i=a;i<=b;i++)
		printf("%d ",i+1);
	printf("\n"); fflush(stdout);
	int u;
	scanf("%d",&u);
	return u;
}

int main(){
	
	int nt;
	scanf("%d",&nt);
	
	while(nt--){
		
		int n;
		scanf("%d",&n);
		int a = 1, b = n-1;
		int d = get(0,a,b);
		while(a != b){
			int m = (a+b)/2;
			int u = get(0,a,m);
			if(u == d)
				b = m;
			else
				a = m+1;
		}
	printf("%d %d\n",1,n-1);
	printf("%d ",a+1);
	for(int i=0;i<n;i++)
		if(i != a) printf("%d ",i+1);
	printf("\n"); fflush(stdout);
	
	int aa;
	scanf("%d",&aa);
	printf("-1 %d\n",aa);
	fflush(stdout);
	}
}