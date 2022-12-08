#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
 
int T;
int n;
string s;

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cin>>s;
		string ans=s;
		int k=1;
		for(int i=2;i<=n;++i){
			string s1;
			for(int j=i-1;j<n;++j)s1+=s[j];
			if(s1.size()&1){
				for(int j=i-2;j>=0;--j)s1+=s[j];
			}
			else{
				for(int j=0;j<=i-2;++j)s1+=s[j];
			}
			if(s1<ans){
				ans=s1;
				k=i;
			}
		}
		cout<<ans<<endl;
		cout<<k<<endl;
	}
}