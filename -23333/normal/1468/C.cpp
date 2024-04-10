#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
int n;
struct node{
	int x,y;
	inline bool operator <(const node &b)const{
		if(x!=b.x)return x<b.x;
		return y>b.y;
    }
};
priority_queue<node>q;
int st[N],tag[N],ans[N];
int main()
{
    scanf("%d",&n);
    int l=1,r=0;
    int opt,x;
    for(int i=1;i<=n;++i){
    	scanf("%d",&opt);
    	if(opt==1){
    		scanf("%d",&x);
    		st[++r]=x;
    		q.push(node{x,r});
    	}
    	else if(opt==2){
    		while(tag[l])l++;
    		ans[++ans[0]]=l;
    		l++;
    //		printf("%d ",l);
    	}
    	else{
    		while(q.top().y<l)q.pop();
    		node xx=q.top();
    		q.pop();
    		tag[xx.y]=1;
    		ans[++ans[0]]=xx.y;
    	//	printf("%d ",xx.y);
    	}
    	
    }
    for(int i=1;i<=ans[0];++i)printf("%d ",ans[i]);
	return 0;
}