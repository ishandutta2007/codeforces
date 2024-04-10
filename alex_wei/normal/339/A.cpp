#include<bits/stdc++.h>
using namespace std;
char c;
int cnt,k[110];
int main()
{
	cin>>k[++cnt];
	while(cin>>c)cin>>k[++cnt];
	sort(k+1,k+cnt+1);
	for(int i=1;i<=cnt;i++){
		cout<<k[i];
		if(i<cnt)cout<<'+';
	}
    return 0;
}