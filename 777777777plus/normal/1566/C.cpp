#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T,n;
string a,b;
bool ban[100005];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cin>>a>>b;
		int ans=0;
		for(int i=0;i<n;++i)ban[i]=0;
		for(int i=0,r=0;i<n;++i){
			if(a[i]!=b[i])ans+=2;
			else{
				if(a[i]=='0')++ans;
				else{
					bool f=0;
					if(i!=0&&a[i-1]=='0'&&b[i-1]=='0'&&!ban[i-1])f=1;
					else if(i!=n-1&&a[i+1]=='0'&&b[i+1]=='0')f=1,ban[i+1]=1;
					if(f)++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
}