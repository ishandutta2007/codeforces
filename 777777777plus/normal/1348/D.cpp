#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 31;

int T;
int n,l[N],r[N];

int main(){
	scanf("%d",&T);
	l[0]=r[0]=1;
	for(int i=1;i<=30;++i){
		l[i]=l[i-1]+1;
		r[i]=r[i-1]+r[i-1]+1;
	}
	while(T--){
		scanf("%d",&n);
		for(int d=1;d<=30;++d)
		if(l[d]<=n&&n<=r[d]){
			printf("%d\n",d);
			int cnt=1,nown=d+1;
			for(int i=1;i<=d;++i){
				int l1=0,r1=cnt;
				while(l1!=r1){
					int mid=l1+r1+1>>1;
					if(nown+1ll*mid*(d-i+1)<=n)l1=mid;
					else r1=mid-1;
				}
				nown+=1ll*l1*(d-i+1);
				cnt+=l1;
				printf("%d ",l1);
			}
			printf("\n");
			assert(n==nown);
			break;
		}
	}
}