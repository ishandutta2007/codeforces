#include<cstdio>
#include<utility>
#include<algorithm>
#define N 100100
using namespace std;
int a[N],b[N],len;
int pos[N],bcnt[N],tpa[N],ppa[N],tbc[N],pbc[N];
bool used[N];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	sort(b,b+m);
	for(int i=0;i<n;i++){
		if(a[i]>=0){
			int x=lower_bound(pos,pos+len,a[i])-pos;
			pos[x]=a[i];
			if(x==len) len++;
			tbc[x]=0;
			tpa[x]=i;
			if(x){
				pbc[i]=tbc[x-1];
				ppa[i]=tpa[x-1];
			}
			else{
				ppa[i]=-1;
				pbc[i]=0;
			}
		}
		else{
			for(int j=m-1,x=len;j>=0;j--){
				while(x&&b[j]<=pos[x-1]) x--;
				pos[x]=b[j];
				if(x==len) len++;
				if(x){
					tbc[x]=tbc[x-1]+1;
					tpa[x]=tpa[x-1];
				}
				else{
					tbc[x]=1;
					tpa[x]=-1;
				}
			}
		}
	}
	int nbc=tbc[len-1],npa=tpa[len-1],bpos=m-1,apos=n-1,pre=-1;
	while(npa>=0||nbc){
		while(nbc--){
			while(a[apos]>=0) apos--;
			while(pre>=0&&b[bpos]>=pre) bpos--;
			pre=a[apos]=b[bpos];
			used[bpos]=1;
		}
		nbc=0;
		if(npa>=0){
			apos=npa-1;
			pre=a[npa];
			nbc=pbc[npa];
			npa=ppa[npa];
		}
	}
	for(int i=0,j=0;i<n;i++){
		if(a[i]<0){
			while(used[j]) j++;
			a[i]=b[j];
			used[j]=1;
		}
		printf("%d ",a[i]);
	}
	return 0;
}