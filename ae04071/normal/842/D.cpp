#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cassert>
#include <cmath>

using namespace std;
typedef long long lli;
typedef pair<int,int> ip;
typedef pair<lli,int> lip;

inline double ABS(double a) {
	return a<0?-a:a;
}
inline double POWER(double a) {
	return a*a;
}
inline lli ABS(lli a) {
	return a<0?-a:a;
}
inline int ABS(int a) {return a<0?-a:a;}
inline lli POWER(lli a) { return a*a; }
inline int POWER(int a) { return a*a; }
inline lli GCD(lli a,lli b) {
	while(b) {
		lli tmp=a%b;a=b;b=tmp;
	}
	return a;
}
inline int GCD(int a,int b) {
	while(b) {
		int tmp=a%b;a=b;b=tmp;
	}
	return a;
}
const double EPS=1e-9;
const int MOD=1e9+7;
const lli INF=1e15;
const int dy[4]={0,-1,0,1},dx[4]={1,0,-1,0};

struct Node{
	Node *le,*ri;
	int cnt,de,lz;
	bool flag;
	Node() {lz=de=cnt=0;le=ri=NULL;flag=false;}
	void init(int d) {
		if(d==20) return;
		le=new Node(); ri=new Node();
		le->init(d+1); ri->init(d+1);
		de=20-d-1;
	}
	void add(int *arr,int d) {
		if(d==20) {
			cnt++; return;
		}
		if(arr[d]) ri->add(arr,d+1);
		else le->add(arr,d+1);
		cnt=le->cnt+ri->cnt;
	}
	void proc_flag(int d) {
		if(d==20) {
			flag=(cnt==0);
			return;
		}
		le->proc_flag(d+1); ri->proc_flag(d+1);
		flag=(le->flag||ri->flag);
	}
	int find(int d) {
		if(d==20) return 0;
		if(lz&(1<<de)) {
			Node *tmp=le; le=ri; ri=tmp;
		}
		le->lz^=lz; ri->lz^=lz;
		lz=0;
		if(le->flag) {
			return le->find(d+1);
		}
		else {
			return ri->find(d+1)|(1<<(de));
		}
	}
};
int n,m;
int arr[21];

void parse(int val) {
	for(int i=0;i<20;i++) {
		arr[i]=val&1;
		val>>=1;
	}
	assert(val==0);
	reverse(arr,arr+20);
}
int main() {
	Node *root=new Node();
	root->init(0);
	int val;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d",&val);
		parse(val);
		root->add(arr,0);
	}
	root->proc_flag(0);
	for(int i=0;i<m;i++) {
		scanf("%d",&val);
		root->lz^=val;
		printf("%d\n",root->find(0));
	}
	return 0;
}