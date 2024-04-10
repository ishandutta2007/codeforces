#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int temp;

	unordered_map<int,std::vector<int> >  M ;
	std::vector<int> A;
	unordered_set<int> S;

	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		if(S.find(temp)==S.end())
		{
		    S.insert(temp);
	    	A.push_back(temp);   
		}
		M[temp].push_back(i);
	}

	sort(A.begin(),A.end());

	std::vector<pair<int,int> > ans;
	int prev_diff,curr_diff;
	bool mark=1;
	for (int i = 0; i <A.size() ; ++i)
	{
		mark=1;
		for (int j = 1; j <M[A[i]].size()-1 ; ++j)
		{
			prev_diff=M[A[i]][j]-M[A[i]][j-1] ;
			curr_diff=M[A[i]][j+1]-M[A[i]][j] ;
			if(prev_diff!=curr_diff)
			{
				mark=0;
				break;
			}
		}
		if(mark)
		{
			if(M[A[i]].size()==1)
			{
				ans.push_back(make_pair(A[i],0));
			}
			else if (M[A[i]].size()==2)
			{
				ans.push_back(make_pair(A[i], M[A[i]][1]-M[A[i]][0]) );
			}
			else
			{
				ans.push_back(make_pair(A[i],curr_diff));
			}
		}
	}

	cout<<ans.size()<<endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}