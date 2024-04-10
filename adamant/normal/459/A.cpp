#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2)
	cout<<x1+y1-y2<<' '<<y1<<' '<<x1+y1-y2<<' '<<y2<<endl;
	else if(y1==y2)
	cout<<x1<<' '<<y1+x1-x2<<' '<<x2<<' '<<y2+x1-x2<<endl;
	else if(abs(y1-y2)==abs(x1-x2))
	cout<<x2<<' '<<y1<<' '<<x1<<' '<<y2<<endl;
	else
	cout<<-1<<endl;
}