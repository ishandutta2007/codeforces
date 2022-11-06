#include<bits/stdc++.h>
using namespace std;
long long a,b,an,v[200005],d[200005],cn,k,c,u[100005],vv[100005],uu[100005],t[200004],cnn;
char s[100005];
map<long long,long long> ve;
bool cmp(long long qq,long long ww)
{
	return qq>ww;
}
int main()
{
	scanf("%lld%lld",&a,&b);cn=0;
	for(int i=1;i<=a;i++)
	{
		scanf("%lld",&d[i]);d[i]=max(d[i],(long long)(i));
		t[++cnn]=b+i-1-d[i];
	}
	sort(t+1,t+cnn+1,cmp);
	long long ll=1;
	for(int i=a;i>=1;i--)
	{
		while(ll<=cnn&&t[ll]>=i)
		{
			if(ve[t[ll]]) cn--,ve[t[ll]]--;
			ll++,cn++;
		}
//		cout<<ll<<" "<<cn<<"\n";
		an=max(an,cn);
		ve[b+i-1-d[i]]++;
		if(b+i-1-d[i]>=i) cn--,ve[b+i-1-d[i]]--;
	}
	printf("%lld",an);
	return 0;
}