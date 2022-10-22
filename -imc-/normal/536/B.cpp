#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
    
const int maxN = 1000500;
char p[maxN * 2];
int z[maxN * 2];

void calcz()
{
    z[0] = strlen(p);
    
    int l = 0, r = 0;
	for (int i = 1; i < z[0]; i++)
	{
		if (i < r)
			z[i] = min (r - i, z[i - l]);

		while (p[z[i]] == p[i + z[i]]) z[i]++;

		if (i + z[i] > r)
		{
			l = i;
			r = i + z[i];
		}
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    
    int sLength, nOccurences;
    scanf("%d %d", &sLength, &nOccurences);
    
    scanf("%s", p);
    
    int pLength = strlen(p);
    for (int i = 0; i < pLength; i++)
        p[i + pLength] = p[i];
    p[2 * pLength] = 0;
    calcz();
    
    int last = -1;
    int nTaken = 0;
    for (int i = 0; i < nOccurences; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        
        if (last != -1 && last + pLength - 1 >= x)
        {
            if (z[x - last] < last + pLength - x)
            {
                printf("0\n");
                return 0;
            }
            
            nTaken += (x + pLength - 1) - (last + pLength - 1);
        }
        else
        {
            nTaken += pLength;
        }
        
        last = x;
    }
    
    int nFree = sLength - nTaken;
    assert(nFree >= 0);
    
    int answer = 1;
    for (int i = 0; i < nFree; i++)
        answer = ((ll)answer * 26) % 1000000007;
    
    printf("%d\n", answer);
    
    return 0;
}