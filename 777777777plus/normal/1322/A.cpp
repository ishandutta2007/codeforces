#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n,a[N];
char s[N];

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=0;
	for(int i=1,last=0;i<=n;++i){
		if(s[i]=='(')a[i]=a[i-1]+1;
		else a[i]=a[i-1]-1;
		if(a[i]<0&&!last){
			last=i;
		}
		if(last&&a[i]==a[last-1]){
			ans+=i-last+1;
			last=0;
		}
	}
	if(a[n]!=0)cout<<-1<<endl;
	else cout<<ans<<endl;
}