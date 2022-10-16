#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<float,int>& a, const pair<float,int>& b)
{
    return(a.first>b.first);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,t1,t2,k1;
	cin>>n>>t1>>t2>>k1;
	cout<<fixed;
    cout<<setprecision(2);
	int a,b;
	int res;
	std::vector<pair<int,int> > vec;

	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		res=max( 100*b*t2 + (100-k1)*(a*t1), 100*a*t2 + (100-k1)*(b*t1) );
		vec.push_back(make_pair(res,i+1));
	}

	stable_sort(vec.begin(),vec.end(),compare);

	for (int i = 0; i < n; ++i)
	{
	    printf("%d %.2lf\n",vec[i].second,0.01*vec[i].first); 
		//cout<<vec[i].second<<" "<<(vec[i].first)*0.01<<endl;
	}

	return 0;
}