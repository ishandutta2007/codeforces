#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int getMul(int n)
{
	int result = 1;
	while (n)
	{
		result *= n % 10;
		n /= 10;
	}
	return result;
}

int main() {
	int n;
	scanf("%d", &n);

	int result = getMul(n);

	int ten = 1;
	if (n >= 10)
	{
		while (true)
		{
			if (n / ten == 0) break;
			int tmp = n % (ten * 10) / ten;
			if (tmp != 9)
			{
				n -= (ten + tmp*ten);
				if (n < 0) continue;
				int newMul = getMul(n);
				if (newMul > result)
					result = newMul;
			}
			ten *= 10;
		}
	}	

	printf("%d", result);
}