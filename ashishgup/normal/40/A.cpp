#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl

const int N=1e5+5;
const int MOD=1e9+7;

int32_t main()
{
    IOS;
   	int x, y;
   	cin>>x>>y;
   	int i=0;
   	while(i*i < x*x + y*y)
   		i++;
   	int black=0;
   	if( (i*i == x*x  + y*y) || (x*y>=0)!=(i%2==0) )
   		black=1;
   	if(black)
   		cout<<"black";
   	else
   		cout<<"white";
    return 0;
}