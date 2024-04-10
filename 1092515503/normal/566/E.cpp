#include<bits/stdc++.h>
using namespace std;
typedef bitset<1010> BS;
int n;
BS bs[1010],bb[1010];
bool testmono(){
	for(int i=1;i<n;i++)if(bs[i]!=bs[i+1])return false;
	for(int i=2;i<=n;i++)printf("%d %d\n",1,i);
	return true;
}
bool nl[1010];
vector<int>res;
bool testbina(){
	BS sb;sb.set();
	for(int i=1;i<=n;i++)sb&=bs[i];
	if(sb.count()!=2)return false;
	int p=sb._Find_first(),q=sb._Find_next(p);
	printf("%d %d\n",p,q);
	int a=1;if(a==p)a++;if(a==q)a++;
	for(int i=1;i<=n;i++)if(bs[i].count()!=n&&bs[i].test(a)){
		for(int j=1;j<=n;j++)if(bs[i].test(j)&&j!=p&&j!=q)printf("%d %d\n",j,p);
		break;
	}
	for(int i=1;i<=n;i++)if(bs[i].count()!=n&&!bs[i].test(a)){
		for(int j=1;j<=n;j++)if(bs[i].test(j)&&j!=p&&j!=q)printf("%d %d\n",j,q);
		break;
	}
	return true;
}
void testcomp(){
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		BS sb=bs[i]&bs[j];
		if(sb.count()!=2)continue;
		int p=sb._Find_first();
		int q=sb._Find_next(p);
		if(bb[p].test(q)||bb[q].test(p))continue;
		bb[p].set(q),bb[q].set(p),bb[p].set(p),bb[q].set(q);
		nl[p]=nl[q]=true;
		printf("%d %d\n",p,q);
	}
	for(int i=1;i<=n;i++){
		if(nl[i])continue;
		int mp=-1,mn=n+1;
		for(int j=1;j<=n;j++)if(bs[j].test(i)&&bs[j].count()<mn)mn=bs[j].count(),mp=j;
		for(int j=1;j<=n;j++)if(!nl[j])bs[mp].reset(j);
//		for(int j=1;j<=n;j++)printf("%d",bs[mp].test(j));puts("");
		for(int j=1;j<=n;j++)if(nl[j]&&bb[j]==bs[mp]){
			printf("%d %d\n",i,j);
			break;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d",&x);
		while(x--)scanf("%d",&y),bs[i].set(y);
	}
	if(testmono())return 0;
	if(testbina())return 0;
	testcomp();
	return 0;
}