#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <long long> primes;
#define N (1000*1000 + 1000)
bool mark[N];

void erat()
{
	primes.push_back(2);
	primes.push_back(3);
	mark[4] = true ; 
	for(long long i=6;i<N;i+=6){
		for(long long j = -1;j<2;j+=2){
			long long l = i + j ;
			if(mark[l]==false)
			{
				primes.push_back(l);
		    	for(long long k=2*l;k<N;k+=l)
		    	mark[k]=true;
			}
		}
	}
}

long long gcd(long long a, long long b)
{
   return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));
}

int main() {
	erat();
	long long l,r;
	cin>>l>>r;
	for(long long i=l;i<=r;i++)
	{
		for(long long j=i+1;j<=r;j++)
		{
			for(long long q=j+1;q<=r;q++)
			{
				if(gcd(i,j)==1 && gcd(j,q)==1 && gcd(i,q)!=1)
				{
					cout<<i<<" "<<j<<" "<<q;
					exit(0);
				}
			}
		}	
	}
	cout<<-1;
	
	return 0;
}