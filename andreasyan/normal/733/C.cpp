#include <iostream>
#include <vector>
using namespace std;

struct ban
{
	int x;
	char s;
};
int b[505],n,m,k;
vector<int> a;
vector<ban> c;
int funkc(int v,int x)
{
	int i,maxu=0,maxi=0;
	if(v-(1+x)==0)
	{
		return v;
	}
	for(i=1+x;i<=v;i++)
	{
		if(a[i]>maxu && ((i-1>=x+1 && a[i]>a[i-1]) || (i+1<=v && a[i]>a[i+1])))
		{
			maxu=a[i];
			maxi=i;
		}
	}
	return maxi;
}
int main()
{
	int y,i,j,x,v;
	ban t;
	cin>>n;
	a.push_back(-1);
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>b[i];
		x=0;
		v=0;
		for(j=1+i;j<a.size();j++)
		{
			x+=a[j];
			if(x==b[i])
			{
				v=j;
				break;
			}
		}
		if(v==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		y=funkc(v,i);
		if(y==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		while(v>1+i)
		{
			if(y-1>=1+i && a[y]>a[y-1])
			{
				t.x=y;
				t.s='L';
				c.push_back(t);
				a[y]+=a[y-1];
				a.erase(a.begin()+y-1);
				y--;
				v--;
				continue;
			}
			if(y+1<=v && a[y]>a[y+1])
			{
				t.x=y;
				t.s='R';
				c.push_back(t);
				a[y]+=a[y+1];
				a.erase(a.begin()+y+1);
				v--;
				continue;
			}
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(a.size()==1+m)
	{
		cout<<"YES"<<endl;
		for(i=0;i<c.size();i++)
		{
			cout<<c[i].x<<' '<<c[i].s<<endl;
		}
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}