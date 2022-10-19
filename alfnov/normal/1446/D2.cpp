#include<bits/stdc++.h>
using namespace std;
int a[200005],mp[200005],s[200005],q1[200005],q2[2000005];
int n,t2=0,he1[2000005],he2[2000005],ggg[10];
vector<int>g[200005];
set<int>se,ss;
void upd(int x)
{
	if(x==n+1)return;
	q2[++t2]=x;
}
int main()
{
	int mx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]]++;
		mx=max(mx,mp[a[i]]);
		g[a[i]].push_back(i);
	}
	int aa=0;
	for(int i=1;i<=n;i++)if(mp[a[i]]==mx)
	{
		if(aa)
		{
			cout<<n<<endl;
			return 0;
		}
		aa=a[i];
		mp[a[i]]=0;
	}
	se.clear();
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1];
		if(a[i]==aa)s[i]++,se.insert(i);
	}
	se.insert(0);
	se.insert(n+1);
	int ans=0;
	for(int i=1;i<=n;i++)if(mp[a[i]])
	{
		ss.clear();
		mp[a[i]]=0;
		int t1=0;
		t2=0;
		for(int j=0;j<g[a[i]].size();j++)q1[++t1]=g[a[i]][j];
		for(int j=1;j<=t1;j++)
		{
			set<int>::iterator it=se.lower_bound(q1[j]),ti=it;
			ti--;
			int a1=*it,a2=*ti,t3=0;
			if(a1!=n+1)
			{
				upd(a1),upd(a1-1),upd(a1+1);
				ggg[++t3]=a1;
				it++;
				int a3=*it;
				if(a3!=n+1)
				{
					upd(a3),upd(a3-1),upd(a3+1);
					ggg[++t3]=a3;
				}
			}
			if(a2!=0)
			{
				upd(a2),upd(a2-1),upd(a2+1);
				ggg[++t3]=a2;
				ti--;
				int a4=*ti;
				if(a4!=0)
				{
					upd(a4),upd(a4-1),upd(a4+1);
					ggg[++t3]=a4;
				}
			}
			for(int j=1;j<=t3;j++)se.erase(ggg[j]),ss.insert(ggg[j]);
		}
		while(ss.size())
		{
			int aa=*ss.begin();
			se.insert(aa);
			ss.erase(aa);
		}
		q2[++t2]=0,q2[++t2]=n;
		sort(q2+1,q2+t2+1);
		t2=unique(q2+1,q2+t2+1)-q2-1;
		map<int,int>an;
		an.clear();
		for(int j=1;j<=t2;j++)he1[j]=s[q2[j]];
		int wz=1;
		for(int j=1;j<=t2;j++)
		{
			while(wz<=t1&&q1[wz]<=q2[j])wz++;
			he2[j]=wz-1;
		}
		for(int j=1;j<=t2;j++)
		{
			if(!an[he1[j]-he2[j]])an[he1[j]-he2[j]]=q2[j]+1;
			else ans=max(ans,q2[j]-an[he1[j]-he2[j]]+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}