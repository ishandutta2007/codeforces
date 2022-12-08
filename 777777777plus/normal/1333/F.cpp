#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int n;
int p[N],ans[N],fac[N];
bool vis[N];

void prepare(){
	for(int i=2;i<=n;++i){
		if(!vis[i])p[++p[0]]=i;
		for(int j=1;j<=p[0]&&p[j]*i<=n;++j){
			vis[i*p[j]]=1;
			ans[i]++;
			if(i%p[j]==0)break;
		}
	}
}

int main(){
	cin>>n;
	prepare();
	ans[1]=p[0];
	int tot=n-1;
	for(int i=1;i<=n/2;++i){
		for(int j=1;j<=ans[i];++j){
			printf("%d ",i);
			tot--;
		}
	}
	//for(int i=1;i<=tot;++i)printf("%d ",n/2);
	printf("\n");
}