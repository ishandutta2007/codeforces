#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[200100];
priority_queue<ll>q;
ll sum;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
		sort(a+1,a+n+1),q.push(sum),sum=0;
		bool ok=true;
		for(int i=n;i&&ok;i--){
			while(q.top()>a[i]){
				ll x=q.top();q.pop();
				q.push(x/2),q.push(x-(x/2));
				if(q.size()>i){ok=false;break;}
			}
			if(q.top()!=a[i]){ok=false;break;}
			q.pop();
		}
		puts(ok?"YES":"NO");
		while(!q.empty())q.pop();
	}
	return 0;
}