#include <bits/stdc++.h>

using namespace std;
const long long N=2750132;

int sieve[N];
vector<int> primes;

void ini()
{
    for(int i=0;i<N;i++) sieve[i]=i;
    primes.push_back(0);
    for(long long o=2;o<N;o++)
    {
        if(sieve[o]==o)
        {
            primes.push_back(o);
            for(long long i=o*o;i<N;i+=o) sieve[i]=min(sieve[i],(int)o);
        }
    }
}

bool is_prime(int n)
{
    return (sieve[n]==n);
}

int main()
{
	int n;
	scanf("%d",&n);
	ini();
	vector<int> one,two;
	int temp;
	for(int i=0;i<2*n;i++)
    {
        scanf("%d",&temp);
        if(is_prime(temp)) one.push_back(temp);
        else two.push_back(temp);
    }
    sort(one.begin(),one.end());
    sort(two.begin(),two.end(),greater<int>());
    vector<int> v(N,0);
    vector<int> res;
    for(int i=0;i<(int)two.size();i++)
    {
        if(v[two[i]]>0)
        {
            v[two[i]]--;
            continue;
        }
        res.push_back(two[i]);
        v[two[i]/sieve[two[i]]]++;
    }
    for(int i=0;i<(int)one.size();i++)
    {
        if(v[one[i]]>0)
        {
            v[one[i]]--;
            continue;
        }
        res.push_back(one[i]);
        v[primes[one[i]]]++;
    }
    for(int i=0;i<n;i++) printf("%d ",res[i]);
    printf("\n");
	return 0;
}