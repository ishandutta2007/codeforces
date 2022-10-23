#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T,f[200],n;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		memset(f,0,sizeof(f));
		for(int i=0;i<s.size();++i)f[s[i]]=1;
		int ans=s.size();
		for(int i=1;i<=130;++i)ans+=f[i];
		printf("%d\n",ans);
	}
    return 0;
}