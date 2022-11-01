#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int N=100001;
	int sieve[N];
	for(int i=1;i<N;i++) sieve[i]=i;
	map<int,int> m;
	int idx=1;
	for(long long o=2;o<N;o++)
    {
        if(sieve[o]==o)
        {
            m.insert(make_pair(o,idx++));
            for(long long i=o*o;i<N;i+=o) sieve[i]=o;
        }
    }
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++) printf("%d ",m[sieve[i]]);
    printf("\n");
	return 0;
}