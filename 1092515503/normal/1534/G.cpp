#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define x first
#define y second
int n;
pii p[800100];
priority_queue<int>q;
priority_queue<int,vector<int>,greater<int> >r;
ll mn;
int tag;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,[](const pii&u,const pii&v){return u.x+u.y<v.x+v.y;});
	q.push(p[1].x),r.push(-p[1].y);
	for(int i=2;i<=n;i++){
//		printf("<%d,%d>\n",p[i].x,p[i].y);
		tag=p[i].x+p[i].y;
		if(p[i].x<q.top()){
			mn+=abs(p[i].x-q.top());
			q.push(p[i].x),q.push(p[i].x);
			r.push(q.top()-tag),q.pop();
		}else if(p[i].x>r.top()+tag){
			mn+=abs(p[i].x-tag-r.top());
			r.push(p[i].x-tag),r.push(p[i].x-tag);
			q.push(r.top()+tag),r.pop();
		}else q.push(p[i].x),r.push(p[i].x-tag);
	}
	printf("%lld\n",mn);
	return 0;
}