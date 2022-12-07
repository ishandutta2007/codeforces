#include<bits/stdc++.h>
using namespace std;
int T,a[1003][1003],n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		char c;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){c='?';
				while(c!='0'&&c!='1')c=getchar();
				a[i][j]=(c-'0');
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){c='?';
				while(c!='0'&&c!='1')c=getchar();
				a[i][j]^=(c-'0');
			}bool ans=1;
		for(int i=1;i<n;i++){
			bool ok0=1,ok1=1;
			for(int j=0;j<n;j++)
				if(a[i][j]==a[0][j])
					ok1=0;
				else
					ok0=0;
			ans&=(ok0|ok1);
		}
		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}