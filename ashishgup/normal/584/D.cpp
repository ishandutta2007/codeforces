#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

bool check_prime(int k)
{
	for(int i=2;i*i<=k;i++)
	{
		if(k%i==0)
			return 0;
	}
	return 1;
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	vector<int> ans;
	if(check_prime(n))
		ans.push_back(n);
	else
	{
		for(int i=n-2;;i--) //Distance between consecutive primes isn't much
		{
			if(check_prime(i)) 
			{
				ans.push_back(i);
				n-=i;
				break;
			}
		}
		if(check_prime(n))
			ans.push_back(n);
		else
		{
			for(int i=2;i<=n;i++)
			{
				if(check_prime(i) && check_prime(n-i)) //Goldbach's Conjecture: Every even number greater than 2 can be expressed as sum of two primes
				{
					ans.push_back(i);
					ans.push_back(n-i);
					break;
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
	return 0;   
}