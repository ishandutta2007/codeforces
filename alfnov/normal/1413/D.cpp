#include<bits/stdc++.h>
using namespace std;
stack<int>s;
int f[1000005];
char c[105];
int jl1[1000005],jl2[1000005];
set<int>ss;
int main()
{
	int n;
	cin>>n;
	int tot=0,mc=0; 
	for(int i=1;i<=2*n;i++)
	{
		scanf("%s",c+1);
		if(c[1]=='+')
		{
			s.push(++tot);
			jl1[i]=0;
			mc=0;
		}
		else
		{
			int a;
			scanf("%d",&a);
			jl1[i]=1,jl2[i]=a;
			if(mc>a||!s.size())
			{
			    puts("NO");
			    return 0;
			}
			else
			{
				f[s.top()]=a;
				s.pop();
			}
			mc=a;
		}
	}
    int ttt=0;
	for(int i=1;i<=2*n;i++)
	{
	    if(!jl1[i])ss.insert(f[++ttt]);
	    else
	    {
	        int tt=*ss.begin();
	        ss.erase(tt);
            if(tt!=jl2[i])
            {
                puts("NO");
                return 0;
            }
	    }
	}
	puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",f[i]);
	return 0;
}