#include<cstdio>
using namespace std;
typedef long long ll;
const int mod=998244353,N=1e7+10;
int n,pr[N],ph,Fl[N],las[N+5],ToT,now,cnt,Ans,F[N+5];
int calc(int x){
	ToT=1;while(x^1){
		cnt=0;now=las[x];while(las[x]==now) x/=now,cnt++;ToT*=cnt+1; 
	}return ToT;
}
int Mod(int x){return x>mod?x-mod:x;}
int main(){
	//freopen("1.in","r",stdin);
    int i,j;scanf("%d",&n);for(i=2;i<=n;i++){
    	!Fl[i]&&(pr[++ph]=i,las[i]=i);for(j=1;j<=ph&&i*pr[j]<=n;j++){Fl[i*pr[j]]=1;las[i*pr[j]]=pr[j];if(i%pr[j]==0) break;}
	} 
	for(i=1;i<=n;i++) F[i]=calc(i);
	for(i=1;i<=n;i++) F[i]=(F[i]+Ans>mod?F[i]+Ans-mod:F[i]+Ans),Ans=(Ans+F[i]>mod?Ans+F[i]-mod:Ans+F[i]);printf("%d\n",F[n]);
}