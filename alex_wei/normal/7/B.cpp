#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int t,n,p[105],cnt;
void debug()
{
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
}
int alloc(int len)
{
	for(int i=1;i<=n-len+1;i++){
		int pd=1;
		for(int j=0;j<len;j++)
			if(p[i+j]!=inf)
				pd=0;
		if(pd){
			cnt++;
			for(int j=0;j<len;j++)
				p[i+j]=cnt;
			return cnt;
		}
	}
	return -1;
}
int erase(int id)
{
	int pd=0;
	for(int i=1;i<=n;i++)
		if(p[i]==id)
			pd=1,p[i]=0;
	if(pd)return id;
	return -1;
}
void defrag()
{
	int k[105],pos=1;
	memset(k,0,sizeof(k));
	for(int i=1;pos<=n;i++)
		while(pos<=n){
			if(p[pos]!=inf){k[i]=p[pos++];break;}
			else pos++;
		}
	for(int i=1;i<=n;i++)
		p[i]=k[i];
}
void update()
{
	for(int i=1;i<=n;i++)
		if(p[i]==0)p[i]=inf;
}
signed main()
{
	cin>>t>>n;
	for(int i=1;i<=t;i++){
		update();
		string s;
		int id;
		cin>>s;
		if(s[0]=='d')defrag();
		else{
			cin>>id;
			if(s[0]=='e'){
				if(erase(id)==-1)cout<<"ILLEGAL_ERASE_ARGUMENT\n";
			}
			else if(s[0]=='a'){
				int get=alloc(id);
				if(get==-1)cout<<"NULL\n";
				else cout<<get<<endl;
			}
		}
//		debug();
	}
    return 0;
}