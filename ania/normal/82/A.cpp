#include<cstdio>

char t[5][123] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main()
{
	int n, m = 5;
	scanf("%d", &n);
	while(n > m)
	{
		n -= m;
		m *= 2;
	}
	int k = m / 5;
	n = (n+k-1) / k;
	printf("%s\n", t[n-1]);
}