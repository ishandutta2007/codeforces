#include<bits/stdc++.h>
using namespace std;
char s[100100];
int main(){
	long long n,x;
	int q;
	cin>>n>>q;
	while(q--){
		cin>>x;
		scanf("%s",s);
		for(int i=0;s[i];i++){
			long long lb=x&-x;
			if(s[i]=='U'){
				if(x==(n+1)>>1) continue;
				if((x>>1)&lb) x-=lb;
				else x+=lb;
			}
			else if(s[i]=='L'){
				x-=lb>>1;
			}
			else x+=lb>>1;
		}
		cout<<x<<endl;
	}
	return 0;
}