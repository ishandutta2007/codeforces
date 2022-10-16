#include <bits/stdc++.h>
using namespace std;

bool myfunction(const pair<int,int> &a, const pair<int,int> &b)
{
	return (a.second<b.second);
}

int main()
{
	int n;
	cin>>n;
	std::vector<pair<int,int> > vect;
	int count1 = 0,count2 = 0,count3 = 0,a;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		vect.push_back(make_pair(i+1,a));
		if(vect[i].second==1)
		{
			count1++;
		}
		else if (vect[i].second==2)
		{
			count2++;
		}
		else
		{
			count3++;
		}
	}
	int w = min(min(count1,count2),count3) ;
	cout<<w<<endl ;
	sort(vect.begin(),vect.end(),myfunction);
	for (int i = 0; i < w; ++i)
	{
		cout<<vect[i].first<<" "<<vect[count1+i].first<<" "<<vect[count1+count2+i].first<<endl;
	}
	return 0;
}