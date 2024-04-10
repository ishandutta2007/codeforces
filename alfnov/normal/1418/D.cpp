#include<bits/stdc++.h>
using namespace std;
int a[100005];
set<int>s1;
multiset<int,greater<int> >s2;
int solve()
{
	if(s1.size()<=2)return 0;
	set<int>::iterator it1=s1.begin(),it2=s1.end();
	it2--;
	int al=(*it2)-(*it1);
	int mx=*s2.begin();
	return al-mx;
}
void err(int x)
{
	multiset<int>::iterator it=s2.lower_bound(x);
	s2.erase(it);
}
void del(int x)
{
	if(s1.size()==1)
	{
		s1.erase(x);
		return;
	}
	set<int>::iterator it=s1.lower_bound(x),it2=it,it3=it;
	it2++;
	if(it2==s1.end())
	{
		it3--;
		err((*it)-(*it3));
		s1.erase(x);
	}else if(it==s1.begin())
	{
		err((*it2)-(*it));
		s1.erase(x);
	}else
	{
		it3--;
		err((*it)-(*it3));
		err((*it2)-(*it));
		s2.insert((*it2)-(*it3));
		s1.erase(x);
	}
}
void ins(int x)
{
	if(!s1.size())
	{
		s1.insert(x);
		return;
	}
	set<int>::iterator it=s1.lower_bound(x),it2=it;
	if(it==s1.begin())
	{
		s2.insert((*it)-x);
		s1.insert(x);
	}else if(it==s1.end())
	{
		it2--;
		s2.insert(x-(*it2));
		s1.insert(x);
	}else
	{
		it2--;
		s2.insert(x-(*it2));
		s2.insert((*it)-x);
		err((*it)-(*it2));
		s1.insert(x);
	}
}
int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s1.insert(a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)s2.insert(a[i]-a[i-1]);
	printf("%d\n",solve());
	for(int i=1;i<=q;i++)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==0)del(x);
		else ins(x);
		printf("%d\n",solve());
	}
	return 0;
}