#include<bits/stdc++.h>
using namespace std;
long long x,n,d,up;
char c;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>c>>d;
		if(c=='+')x+=d;
		else{
			if(x>=d)x-=d;
			else up++;
		}
	}
	cout<<x<<" "<<up;
    return 0;
}