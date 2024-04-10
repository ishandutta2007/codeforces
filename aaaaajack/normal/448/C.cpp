#include<cstdio>
#include<stack>
#include<algorithm>
#define N 10000
using namespace std;
int main(){
	int a[N]={},tmp,ps,ph,pf,ns,n,i;
	stack<int> s,h,f;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=0;i<=n+1;i++){
		ns=i;
		tmp=0;
		while(!h.empty()&&a[i]<h.top()){
			ps=s.top();
			s.pop();
			ph=h.top();
			h.pop();
			pf=f.top();
			f.pop();
			ns=ps;
			tmp=min(pf+ph-max(a[i],h.top()),i-ps);
			ns=ps;
			if(a[i]<=h.top()) f.top()+=tmp;
		}
		if(h.empty()||a[i]>h.top()){
			s.push(ns);
			h.push(a[i]);
			f.push(tmp);
		}
	}
	printf("%d\n",f.top());		
	return 0;
}