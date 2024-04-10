#include <stdio.h>
#include <algorithm>

int n;
int ltree[1<<18],tree[1<<18], val[100000];
int nodeNum=1;

void Push(int node, bool flag)
{
	tree[node]+=ltree[node];
	if(flag) {
		ltree[node*2]+=ltree[node];
		ltree[node*2+1]+=ltree[node];
	}
	ltree[node]=0;
}

int Update(int node, int st, int fi, int le, int ri, int v)
{
	Push(node, st!=fi);

	if(fi<le || st>ri) return tree[node];
	else if(le<=st && fi<=ri) {
		ltree[node]+=v;
		Push(node, st!=fi);
		return tree[node];
	}
	else {
		return tree[node]=std::max(Update(node*2,st,(st+fi)/2,le,ri,v), Update(node*2+1,(st+fi)/2+1,fi,le,ri,v));
	}
}

int Find()
{
	int node=1;
	while(node<nodeNum) {
		Push(node, node<nodeNum);
		if(tree[node]<=0) return -1;
		Push(node*2,node*2<nodeNum);
		Push(node*2+1,node*2+1<nodeNum);
		if(tree[node*2+1]>0) node=node*2+1;
		else node=node*2;
	}
	if(tree[node]<=0) return -1;
	else return val[node-nodeNum];
}

int main()
{
	scanf("%d",&n);
	while(nodeNum<n) nodeNum<<=1;

	int ord, type, num;
	for(int tc=0; tc<n; tc++) {
		scanf("%d %d", &ord, &type);
		ord--;
		if(type) {
			scanf("%d", &num);
			val[ord]=num;
			Update(1,0,nodeNum-1,0,ord,1);
			printf("%d\n",Find());
		}
		else {
			Update(1,0,nodeNum-1,0,ord,-1);
			printf("%d\n",Find());
		}
	}

	return 0;
}