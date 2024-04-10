#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
 
int T;
 
int main(){
	cin>>T;
	while(T--){
		int n,u,r,d,l;
		cin>>n>>u>>r>>d>>l;
		bool flag=0;
		for(int i=0;i<(1<<4);++i){
			if(i&1)l--,u--;
			if(i&2)l--,d--;
			if(i&4)r--,u--;
			if(i&8)r--,d--;
			if(l>=0&&r>=0&&u>=0&&d>=0&&l<=n-2&&r<=n-2&&u<=n-2&&d<=n-2)flag=1;
			if(i&1)l++,u++;
			if(i&2)l++,d++;
			if(i&4)r++,u++;
			if(i&8)r++,d++;
		}
		puts(flag?"YES":"NO");
	}
}