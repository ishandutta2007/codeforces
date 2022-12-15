#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
typedef long long lli;

int cache[5000][5000],n;
char str[5010];
lli k;

struct node{
	node *nxt[2];
	lli cnt,sum;
	node() {
		nxt[0]=nxt[1]=NULL;
		cnt=sum=0;
	}
	void add(int s,int i){
		if(s<=i) cnt += cache[s][i];
		if(i==n-1) return;

		int nx=str[i+1]-'a';
		if(nxt[nx]==NULL) nxt[nx]=new node();
		nxt[nx]->add(s,i+1);
	}
	void dfs() {
		sum += cnt;
		for(int i=0;i<2;i++) if(nxt[i]!=NULL) {
			nxt[i]->dfs();
			sum += nxt[i]->sum;
		}
	}
	void find(lli k) {
		if(k<=cnt) return;
		k-=cnt;

		if(nxt[0] && k<=nxt[0]->sum) {
			printf("a");
			nxt[0]->find(k);
		}
		else {
			printf("b");
			nxt[1]->find(k-(nxt[0] ? nxt[0]->sum : 0));
		}
	}
}*root;

int main() {
	scanf("%s",str);
	n=strlen(str);

	for(int i=0;i<n;i++) cache[i][i]=1;
	for(int i=0;i<n-1;i++) cache[i][i+1]=(str[i]==str[i+1]);
	for(int i=0;i<n-2;i++) cache[i][i+2]=(str[i]==str[i+2]);
	for(int i=0;i<n-3;i++) cache[i][i+3]=(str[i]==str[i+3]);
	
	for(int l=5;l<=n;l++) {
		for(int i=0;i<=n-l;i++) {
			cache[i][i+l-1] = (str[i]==str[i+l-1] && cache[i+2][i+l-3]);
		}
	}

	root = new node();
	for(int i=0;i<n;i++) {
		root->add(i,i-1);
	}
	root->dfs();
	
	scanf("%lld",&k);
	root->find(k);

	return 0;
}