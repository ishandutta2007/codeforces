#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=1003;

long long n,k;

int main()
{
	//freopen("input.txt","r",stdin);
	cin>>n>>k;
	k=min(k,n);
	long long ans=0;
	for(int q=k;q>=1;--q)
    {
        if(q==1)
            ans+=1;
        else if(q==2)
        {
            ans+=(n*(n-1)/2);
        }
        else if(q==3)
        {
            ans+=((n*(n-1)*(n-2)/6)*2);
        }
        else
        {
            ans+=((n*(n-1)*(n-2)*(n-3)/24)*9);
        }
    }
    cout<<ans<<endl;
	return 0;
}