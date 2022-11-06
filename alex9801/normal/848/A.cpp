#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int k, t, i, j, l;
    scanf("%d", &k);
    
    for(i=0;i<26;i++)
    {
    	t=0;
    	for(j=1;;j++)
    	{
    		if(t+j > k)
    		{
    			for(l=0;l<j;l++)
    				printf("%c", 'a'+i);
    			k -= t;
    			break;
    		}
    		t += j;
    	}
    }
    return 0;
}