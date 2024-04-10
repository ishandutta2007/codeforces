#include<bits/stdc++.h>
using namespace std;
int T,n;
const int N=100000;
int pri[100100];
void sieve(){
	for(int i=2;i<=N;i++){
		if(!pri[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			pri[i*pri[j]]=true;
			if(!(i%pri[j]))break;
		}
	}
} 
int main(){
	scanf("%d",&T),sieve();
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)printf("%d ",pri[i]);puts("");
	}
	return 0;
}