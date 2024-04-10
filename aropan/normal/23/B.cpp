#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int k, x;
    scanf("%d", &k);
    while (k--)
    {
		scanf("%d", &x);
		printf("%d\n", max(0, x - 2));
	}
    
    
    

    return 0;
}