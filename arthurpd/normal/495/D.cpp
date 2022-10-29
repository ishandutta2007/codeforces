#include <stdio.h>
#include <string.h>
#include <iostream>

const long long mod = 1000000007LL;

char s1[112345], s2[112345];
int n, m;
int found[112345];
int next[112345];
long long tab[112345];
long long s[112345];
int prox[112345];

long long pd(int i)
{
	if(i == n)
		return 1;
	long long retv = 0;
	if(found[i])
		retv += pd(i+m);
	retv += pd(i+1);
	return retv;
}

void process()
{
	next[0] = next[1] = 0;
	for(int i = 2; i <= m; i++)
	{
		int x = next[i-1];
		while(s2[x] != s2[i-1] && x != 0)
			x = next[x];
		next[i] = (s2[x] == s2[i-1]) ? x+1 : 0;
	}
}


int
main(void)
{
	scanf("%s %s", s1, s2);
	n = strlen(s1), m = strlen(s2);
	
	process();
	int match = 0;
	for(int i = 0; i < n; i++)
	{
		while(s1[i] != s2[match] && match != 0)
			match = next[match];
		
		if(s1[i] == s2[match])
			match++;
		
		if(match == m)
			match = next[match], found[i - m + 1]++;
	}
	
	prox[n] = -1;
	tab[n] = 1;
	s[n] = 1;
	
	for(int i = n-1; i >= 0; i--)
	{
		if(found[i])
			prox[i] = i;
		else
			prox[i] = prox[i+1];
		
		
		tab[i] += tab[i+1];

		if(prox[i] != -1)
			tab[i] += s[m+prox[i]];
		
		tab[i] = tab[i] % mod;
		
		s[i] = (s[i+1] + tab[i]) % mod;
	}
	
	std::cout << (tab[0] - 1 + mod)%mod << '\n';
}