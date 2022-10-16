#include <bits/stdc++.h>
using namespace std;

int isprime(int N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i = n+1; i<=m ; ++i)
	{
		if (isprime(i))
		{
			if(i==m)
			{
				cout<<"YES";
				return 0;
			}
			cout<<"NO";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}