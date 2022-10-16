#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,temp,p,q;
	unordered_set <int> S;

	cin>>n;
	//cout<<"n value is"<<n<<endl;

	cin>>p;
	//cout<<"P value is"<<p<<endl;
	for (int i = 0; i < p; ++i)
	{
		cin>>temp;
		//cout<<"P is"<<temp<<endl;
		S.insert(temp);
	}
    
    
	cin>>q;
	//cout<<"Q value is"<<q<<endl;
	for (int i = 0; i < q; ++i)
	{
		cin>>temp;
		//cout<<"Q is"<<temp<<endl;
		S.insert(temp);
	}

	for (int i = 1; i <= n; ++i)
	{
		if(S.find(i)==S.end())
		{
			cout<<"Oh, my keyboard!";
			return 0;
		}
	}
	cout<<"I become the guy.";
	return 0;
}