#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2+5;

int T;
int n,m;
int a[N][N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)
			if(i==1&&j==1){
				putchar('W');
			}
			else{
				putchar('B');
			}
			puts("");
		}
	}
}