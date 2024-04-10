#include<cstdio>
#include<cstring>
#define N 100100
using namespace std;
int cnt[N],a[N],tmp[N];
int main(){
	int n,i,j,k,l,r;
	int odd=0,mid;
	long long ans=0;
	bool palin=true;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(i=1;i<=n;i++){
		if(cnt[i]&1){
			odd++;
			mid=i;
		}
	}
	for(i=1;i<=n;i++){
		if(a[i]!=a[n+1-i]) palin=false;
	}
	if((n&1)!=odd){
		printf("0\n");
	}
	else if(palin){
		printf("%I64d\n",1LL*n*(n+1)/2);
	}
	else{
		j=n;
		k=0;
		bool flag=false;
		int fix=0;
		memset(tmp,0,sizeof(tmp));
		while(j>(n+1)/2&&tmp[a[j]]<cnt[a[j]]/2){
			tmp[a[j]]++;
			j--;
		}
		memset(tmp,0,sizeof(tmp));
		if(j==(n+1)/2) fix=1;
		for(i=1;i<=n/2;i++){
			if(flag||a[i-1]!=a[n+2-i]){
				ans+=k;
				flag=true;
			}
			else{
				ans+=(n-j+1)-fix;
				k++;
			}
			tmp[a[i]]++;
			if(tmp[a[i]]>cnt[a[i]]/2){
				break;
			}
			//printf("%d %I64d\n",i,ans);
		}
		//printf("%I64d\n",ans);
		if(j==(n+1)/2){
			if(n%2&&a[j]!=mid) r=j;
			else{
				r=j;
				while(r>0&&a[r]==a[n+1-r]) r--;
			}
			l=1;
			while(l<=j&&a[l]==a[n+1-l]) l++;
			ans+=1LL*l*(j-r+1);
		}
		//printf("%I64d\n",ans);
		j=1;
		memset(tmp,0,sizeof(tmp));
		flag=false;
		k=0;
		while(j<=n/2&&tmp[a[j]]<cnt[a[j]]/2) tmp[a[j++]]++;
		if(j==n/2+1){
			if(n%2&&a[j]!=mid) l=j;
			else{
				l=j;
				while(l<=n&&a[l]==a[n+1-l]) l++;
			}
			r=n;
			while(r>=j&&a[r]==a[n+1-r]) r--;
			ans+=1LL*(l-j+1)*(n+1-r);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}