#include<bits/stdc++.h>
using namespace std;
int n,i,ans=1<<30;
char c[1005];
int p(int x,int y)
{
    return min(abs(x-y),26-abs(x-y));
}
int main(){
	scanf("%d",&n);
	scanf("%s",c+1);
	for(i=1;i<=n-3;i++)
        ans=min(ans,p(c[i],'A')+p(c[i+1],'C')+p(c[i+2],'T')+p(c[i+3],'G'));
	cout<<ans;
}