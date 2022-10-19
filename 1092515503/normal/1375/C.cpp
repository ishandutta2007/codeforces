#include<bits/stdc++.h>
using namespace std;
int T,n,a[300100];
stack<int>s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		while(!s.empty())s.pop();
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		s.push(a[1]);
		for(int i=2;i<=n;i++){
			if(s.top()>a[i])s.push(a[i]);
			else{
				while(s.size()>=2&&s.top()<a[i])s.pop();
				if(s.top()>a[i])s.push(a[i]);
			}
		}
		puts(s.size()==1?"YES":"NO");
	}
	return 0;
}