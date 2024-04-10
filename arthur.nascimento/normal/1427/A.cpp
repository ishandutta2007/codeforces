#include <bits/stdc++.h>

#define maxn 100100

#define maxK 4100

#define ll long long

#define pb push_back

#define pii pair<int,int>

#define mod 1000000007 

#define debug(args...) //fprintf(stderr,args)

using namespace std;
int v[maxn];
main(){
	int nt;
	scanf("%d",&nt);
	while(nt--){
		int n;
		int s = 0, sn = 0, sp = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			s += v[i];
			if(v[i] > 0) sp += v[i];
			if(v[i] < 0) sn -= v[i];
		}
		if(s == 0){
			printf("NO\n");
		}
		else {
			printf("YES\n");
			sort(v,v+n);
			if(sp > sn)
				reverse(v,v+n);
			for(int i=0;i<n;i++)
				printf("%d ",v[i]);
			printf("\n");
		}
	}
}