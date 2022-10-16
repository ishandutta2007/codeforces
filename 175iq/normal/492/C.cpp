#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<long int,long int>& a, const pair<long int,long int>& b)
{
	return (a.second<b.second);
}

int main()
{
	long long int n,r,avg;
	cin>>n>>r>>avg;

	long long int total=avg*n;
    //cout<<"TOTAL "<<total<<endl;
    
	long long int ans=0;
	long long int a,b;
	std::vector<pair<long int,long int> > A;

	long long int temp_tot=0;

	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		A.push_back(make_pair(a,b));
		temp_tot+=a;
	}
    
    //cout<<"TEMP_TOTAL "<<temp_tot<<endl;
	sort(A.begin(),A.end(),compare);

	long long int inc=total-temp_tot;
	
	long long int temp;
	int i=0;
	while(inc>0)
	{
		temp=r-A[i].first;
		//cout<<"temp "<<temp<<endl;
		if(inc>=temp)
		{
			inc-=temp;
			ans+=(A[i].second)*temp;
		}
		else
		{
			ans+=(A[i].second)*inc;
			inc=0;
		}
		i++;
		if(i==A.size())
		{
			break;
		}
	}

	cout<<ans;
	return 0;
}