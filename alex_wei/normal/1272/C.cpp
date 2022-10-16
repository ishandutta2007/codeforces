#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	int x=0,sign=1;char s=getchar();
	while(!isdigit(s)){
		if(s=='-')sign=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*sign;
}
ll n,k,ans,pd[128],cnt;
string s;
char c;
int main(){
	cin>>n>>k>>s;
	for(int i=1;i<=k;i++)cin>>c,pd[c]=1;
	for(int i=0;i<s.size();i++)
		if(pd[s[i]])cnt++;
		else ans+=(cnt+1)*cnt/2,cnt=0;
	cout<<ans+(cnt+1)*cnt/2;
    return 0;
}