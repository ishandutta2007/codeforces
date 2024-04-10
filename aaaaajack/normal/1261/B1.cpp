#include<bits/stdc++.h>
#define N 200100
using namespace std;
int a[N],id[N];
int qid[N],k[N],d[N],ans[N];
int f[N];
bool cmp(int i,int j){
	return a[i]>a[j]||a[i]==a[j]&&i<j;
}
bool cmp2(int i,int j){
	return k[i]<k[j];
}
void add(int x){
	while(x<N){
		f[x]++;
		x+=x&-x;
	}
}
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		id[i]=i;
	}
	sort(id,id+n,cmp);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		qid[i]=i;
		scanf("%d%d",&k[i],&d[i]);
	}
	sort(qid,qid+m,cmp2);
	int cur=0;
	for(int i=0;i<m;i++){
		int tk=k[qid[i]],td=d[qid[i]];
		while(cur<tk){
			add(id[cur++]+1);
		}
		int tmp=0,st=1<<17;
		while(st){
			if(tmp+st<N&&f[tmp+st]<td){
				tmp+=st;
				td-=f[tmp];
			}
			st>>=1;
		}
		ans[qid[i]]=tmp;
	}
	for(int i=0;i<m;i++){
		printf("%d\n",a[ans[i]]);
	}
	return 0;
}