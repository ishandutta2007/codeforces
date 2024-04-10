#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1001*1000)
#define K ((ll)20)

ll n;
bitset <N> mark;

int main()
{
	cin>>n;
	mark[1]=1;
	for(long long i=2;i<N;i++)
		if(!mark[i])
			for(long long j=i*i;j<N;j+=i)
				mark[j]=1;
	for(int i=1;i<=1000;i++)if(mark[n*i+1])return cout<<i,0;
	return 0;
}