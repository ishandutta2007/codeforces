#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
struct A{
	int o[100],c;
};
map<int,A>Map;
set<int>V;
set<int>::iterator it;
int n,m,w[51],i,C,j,O[10001],tC,k,t;
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	V.insert(w[0]);printf("1 %d\n",w[0]);C++;
	Map[w[0]].o[0]=w[0],Map[w[0]].c=1;
	for(i=1;i<n;i++){
		if(C==m)break;
		j=0;
		for(it=V.begin();it!=V.end();it++){
			O[j++]=*it;
		}
		tC=C;
		if(V.find(w[i])==V.end()){
			C++;
			V.insert(w[i]);
			printf("%d ",1);
			Map[w[i]].c=1;
			Map[w[i]].o[0]=w[i];
			printf("%d\n",w[i]);
		}
		if(C==m)break;
		for(j=0;j<tC;j++){
			if(V.find(w[i]+O[j])==V.end()){
				C++;
				V.insert(w[i]+O[j]);
				printf("%d ",Map[O[j]].c+1);
				for(k=0;k<Map[O[j]].c;k++){
					t=Map[O[j]].o[k];
					Map[w[i]+O[j]].o[k]=t;
					printf("%d ",t);
				}
				Map[O[j]+w[i]].c=k+1;
				Map[w[i]+O[j]].o[k]=w[i];
				printf("%d\n",w[i]);
			}
			if(C==m)break;
		}
	}
	return 0;
}