#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=305;

int n;
int a[N];
string ans[N];

void work(int k)
{
	string prev=ans[k-1];
	int sum=a[k];
	int len=prev.size();
	string now=prev;
	for(int i=len-1;i>=0;i--)
	{
		for(int d=prev[i]-'0'+1;d<=9;d++)
		{
			int cur=d;
			for(int j=0;j<i;j++)
			{
				cur+=prev[j]-'0';
			}
			if(cur<=sum&&cur+9*(len-1-i)>=sum)
			{
				now[i]=d+'0';
				sum-=cur;
				for(int j=len-1;j>i;j--)
				{
					now[j]=min(sum, 9)+'0';
					sum-=min(sum, 9);
				}
				ans[k]=now;
				return;
			}
		}
	}
	for(int newlen=len+1;;newlen++)
	{
		if(9*newlen>=sum)
		{
			now="";
			int cur=0;
			for(int i=0;i<newlen;i++)
			{
				for(int d=0;d<='9';d++)
				{
					if(i==0&&d==0)
						continue;
					if(cur+d<=sum&&(cur+d+9*(newlen-i-1))>=sum)
					{
						now+=(char)(d+'0');
						cur+=d;
						break;
					}
				}
			}
			ans[k]=now;
			return;
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	ans[0]="0";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		work(i);
		cout<<ans[i]<<endl;
	}
	return 0;
}