#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n;
char s[N];

bool can(int ans){
	int x=0;
	while(x!=n+1){
		bool flag=0;
		for(int i=min(n+1,x+ans);i>=x+1;--i)
		if(s[i]=='R'){
			x=i;
			flag=1;
			break;
		}
		if(!flag)return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		s[n+1]='R';
		int l=1,r=n+1;
		while(l!=r){
			int mid=l+r>>1;
			if(can(mid))r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
}