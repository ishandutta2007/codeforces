/*
2 3 6 7

let R is bigger.

L R choose two larger;

R L choose a smallest, and a big;

L L choose a big, and a smallest;

R R choose a smallestR and a smallestL.
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int a[N],s[N];
string S;
struct Node{
	int pos;
	int l;
	int num;
};
deque<Node>q;
Node shun[N];
bool cmp(Node k1,Node k2){
	return k1.pos<k2.pos;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	cin>>S;
	for(int i=0;i<n;i++){
		if(S[i]=='L') s[i+1]=0;
		else s[i+1]=1;
	}
	for(int i=1;i<n;i+=2){
		if(s[i-1]==1){
			if(s[i]==0 && s[i+1]==0) q.push_back((Node){i,0,0}),q.push_front((Node){(i+1),1,0});
			if(s[i]==0 && s[i+1]==1) q.push_back((Node){(i),0,0}),q.push_back((Node){i+1,1,0});
			if(s[i]==1 && s[i+1]==0) q.push_front((Node){i,1,0}),q.push_back((Node){(i+1),0,0});
			if(s[i]==1 && s[i+1]==1) q.push_back((Node){i+1,0,0}),q.push_back((Node){(i),1,0});
		}
		else{
			if(s[i]==1 && s[i+1]==1) q.push_back((Node){i,1,0}),q.push_front((Node){(i+1),0,0});
			if(s[i]==1 && s[i+1]==0) q.push_back((Node){(i),1,0}),q.push_back((Node){(i+1),0,0});
			if(s[i]==0 && s[i+1]==1) q.push_front((Node){i,0,0}),q.push_back((Node){(i+1),1,0});
			if(s[i]==0 && s[i+1]==0) q.push_back((Node){i+1,1,0}),q.push_back((Node){(i),0,0});
		}
	}
	if(n&1){
		q.push_back((Node){n,s[n]});
	}
	int tot=0;
	while(!q.empty()){
		tot++;
		shun[tot]=q.front();
		q.pop_front();
		shun[tot].num=a[tot];
	}
	sort(shun+1,shun+n+1,cmp);
	for(int i=1;i<=n;i++){
		printf("%d ",shun[i].num);
		if(shun[i].l==0) printf("L\n");
		else printf("R\n");
	}
}