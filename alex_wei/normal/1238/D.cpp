#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,tmp,las;
string s;
int main()
{
	cin>>n>>s;
	s+='C';
	for(int i=0;i<=n;i++){
		if(i>0&&s[i]!=s[i-1]){
//			cout<<"tmp:"<<tmp<<endl;
			ans+=(tmp-1)*tmp/2;
			if(!las){las=tmp;tmp=1;/*cout<<ans<<endl*/;continue;}
			if(tmp==1){
				int kk=i-tmp-las;
				las=tmp,tmp=1;
				ans+=kk;
//				cout<<ans<<endl;
				continue;
			}
			int kk=i-tmp;
//			cout<<"kk:"<<kk<<"las:"<<las<<endl;
			if(las==1){
//				cout<<ans<<endl;
				ans+=(tmp-1)*(kk-1);
//				cout<<ans<<endl;
				ans+=kk-1;
			}
			else{
				ans+=(tmp-1)*(kk-1);
				ans+=i-tmp-las;
			}
			las=tmp;
			tmp=1;
		}
		else tmp++;
//		cout<<ans<<endl;
	}
	cout<<ans;
    return 0;
}