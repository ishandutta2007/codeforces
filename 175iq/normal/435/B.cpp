#include <bits/stdc++.h>
using namespace std;

int main()
{	
	string S;
	int k;
	cin>>S>>k;

	int t;
	for (int i = 0; i < S.size()-1; ++i)
	{
		t=i;
		for (int j = i+1; (j<S.size())&&(j<=i+k) ; ++j)
		{
			if(S[j]>S[t])
			{
				t=j;
			}
		}
		k-=(t-i);
		while(t!=i)
		{
			swap(S[t],S[t-1]);
			t--;
		}
	}

	cout<<S;
	return 0;
}