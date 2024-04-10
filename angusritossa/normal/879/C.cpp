#include <cstdio>
#include <utility>
using namespace std;
int _or, _xor, n;
pair<char, int> in[1000010];
int alloff, allon;
int main()
{
	scanf("%d", &n);
	allon = 1 << 20;
	allon--;
	//printf("%d %d\n", allon, alloff);
	for (int i = 0; i < n; i++)
	{
		scanf(" %c%d", &in[i].first, &in[i].second);
		if (in[i].first == '&')
		{
			alloff &= in[i].second;
			allon &= in[i].second;
		}
		if (in[i].first == '|')
		{
			alloff |= in[i].second;
			allon |= in[i].second;
		}
		if (in[i].first == '^')
		{
			alloff ^= in[i].second;
			allon ^= in[i].second;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if ((alloff & (1 << i)) && (allon & (1 << i)))
		{
			_or |= (1 << i);
		}
		else if ((alloff & (1 << i)) == false && (allon & (1 << i)) == false)
		{
			//printf("%d\n", i);
			_or |= (1 << i);
			_xor |= (1 << i);
		}
		else if ((alloff & (1 << i)) && (allon & (1 << i)) == false)
		{
			_xor |= (1 << i);
		}
	}
	printf("%d\n| %d\n^ %d\n", 2, _or, _xor);
}