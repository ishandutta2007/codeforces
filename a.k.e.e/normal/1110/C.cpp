#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int Q;

int main()
{
    cin>>Q;
    while(Q--)
    {
    	int x,t=0;
    	cin>>x;
    	for(;;++t)
    		if((1<<t)>x)break;
    	if(x<(1<<t)-1)cout<<((1<<t)-1)<<endl;
    	else
    	{
    		bool flag=0;
    		for(int i=2;i*i<=x;i++)
    			if(x%i==0)
				{
					printf("%d\n",x/i);
					flag=1;break;
				}
			if(!flag)printf("1\n");
    	}
    }
    return 0;
}