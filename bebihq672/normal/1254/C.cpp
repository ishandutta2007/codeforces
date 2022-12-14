#include<bits/stdc++.h>
using namespace std;

struct Point{
	int id;
	long long area;
	Point(){}
	Point(int _id,long long _area)
	{
		id=_id;
		area=_area;
	}
};
long long a[1010];
vector<Point> fro,beh;

bool cmp(const Point &A,const Point &B)
{
	return A.area<B.area;
}

int main()
{
	int n;
	cin>>n;
	int p2=2;
	for(int i=3;i<=n;i++)
	{
		cout<<2<<" "<<1<<" "<<p2<<" "<<i<<endl;
		cout.flush();
		int res;
		cin>>res;
		if(res==-1)
			p2=i;
	}
	
	long long max_area=0;
	int max_id=1;
	
	for(int i=2;i<=n;i++)
	if(i!=p2)
	{
		cout<<1<<" "<<1<<" "<<p2<<" "<<i<<endl;
		cout.flush();
		long long res;
		cin>>res;
		a[i]=res;
		if(res>max_area)
		{
			max_area=res;
			max_id=i;
		}
	}
	
	for(int i=1;i<=n;i++)
	if(a[i]>0&&i!=max_id)
	{
		cout<<2<<" "<<1<<" "<<i<<" "<<max_id<<endl;
		cout.flush();
		int res;
		cin>>res;
		if(res==1)
			fro.push_back(Point(i,a[i]));
		else
			beh.push_back(Point(i,a[i]));
	}
	cout<<0<<" ";
	if(!fro.empty())
		sort(fro.begin(),fro.end(),cmp);
	if(!beh.empty())
		sort(beh.begin(),beh.end(),cmp);
	cout<<1<<" "<<p2<<" ";
	for(int i=0;i<(int)fro.size();i++)
		cout<<fro[i].id<<" ";
	cout<<max_id<<" ";
	for(int i=(int)beh.size()-1;i>=0;i--)
		cout<<beh[i].id<<" ";
	cout<<endl;
	cout.flush();
	return 0;
}