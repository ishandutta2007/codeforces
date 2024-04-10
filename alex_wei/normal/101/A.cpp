#include<bits/stdc++.h>
using namespace std;
string s;
struct node{
	int num,val;
}p[27];
bool cmp(node a,node b){return a.num>b.num;}
int k,sum,ans,rem[27];
int main()
{
	cin>>s>>k;
	if(k>=s.size())cout<<"0\n",exit(0);
	for(int i=0;i<26;i++)p[i].val=i;
	for(int i=0;i<s.size();i++)p[s[i]-'a'].num++;
	sort(p,p+26,cmp);
	for(int i=0;i<26;i++){
		sum+=p[i].num;
		rem[p[i].val]=1,ans++;
		if(sum>=(int)s.size()-k)break;
	}
	cout<<ans<<endl;
	for(int i=0;i<s.size();i++)
		if(rem[s[i]-'a'])
			cout<<s[i];
	return 0;
}