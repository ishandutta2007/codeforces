#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string,string> back;
	unordered_map<string,string>:: iterator it;

	int q,n;
	cin>>q;	

	string S1,S2;
	for (int i = 0; i < q; ++i)
	{
		cin>>S1>>S2;
		it=back.find(S1);
		if(it==back.end())
		{
			back[S2]=S1;	
		}
		else
		{
			back[S2]=it->second;
			back.erase(it);
		}
	}
	cout<<back.size()<<'\n';

	for(auto i:back)
	{
		cout<<i.second<<" "<<i.first<<'\n';
	}
	return 0;
}