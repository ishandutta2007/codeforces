#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[1000039],tot,ansx[1000039],ansy[1000039],heads;
int h[1000039];
int s[1000039],head,s2[1000039],head2;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);
	tot=n;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=n;i>=1;i--){
		if(a[i]==1){
			ansx[++heads]=tot;ansy[heads]=i;
			s[++head]=i;
			h[i]=tot;
			tot--;
		}
		else if(a[i]==2){
			if(!head){printf("-1");return 0;}
			ansx[++heads]=h[s[head--]];ansy[heads]=i;
			h[i]=ansx[heads];
			s2[++head2]=i;
		}
		else if(a[i]==3){
			if(!head&&!head2){printf("-1");return 0;}
			if(head2){
			    ansx[++heads]=tot;ansy[heads]=i;
			    ansx[++heads]=tot;ansy[heads]=s2[head2--];
			    h[i]=ansx[heads-1];
			    s2[++head2]=i;
				tot--;
			}
			else{
			    ansx[++heads]=tot;ansy[heads]=i;
			    ansx[++heads]=tot;ansy[heads]=s[head--];
			    h[i]=ansx[heads-1];
			    s2[++head2]=i;
				tot--;
			}
		}
	}
	printf("%d\n",heads);
	for(i=1;i<=heads;i++) printf("%d %d\n",ansx[i],ansy[i]);
}