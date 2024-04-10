#include<cstdio>
#include<algorithm>
using namespace std;
char t[100001];
int l[100001],c[100001];
long long len[100001];
int main(){
	int m,n,i,j,ans;
	long long x;
	char sp;
	scanf("%d",&m);
	len[0]=0;
	for(i=1;i<=m;i++){
		scanf(" %c",&t[i]);
		if(t[i]=='1'){
			scanf("%d",&l[i]);
			len[i]=len[i-1]+1;
		}
		else{
			scanf("%d%d",&l[i],&c[i]);
			len[i]=len[i-1]+l[i]*c[i];
		}
	}
	scanf("%d",&n);
	while(n--){
		scanf("%I64d%c",&x,&sp);
		while(1){
			i=lower_bound(len,len+m+1,x)-len;
			if(t[i]=='1'){
				ans=l[i];
				break;
			}
			else{
				x=(x-len[i-1]-1)%l[i]+1;
			}
		}
		printf("%d%c",ans,sp);
	}
	return 0;
}