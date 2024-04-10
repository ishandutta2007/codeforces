#include <iostream>
using namespace std;
 
int main() 
{
	int r,g,b;
	cin>>r>>g>>b;
	
	int ans =0;
	int x = min(r,min(g,b));
    for (int i = 0; i <= min(2,x); i++) 
    {
        int r1=r-i;
        int g1=g-i;
        int b1=b-i;
        ans =  max(ans, i+ (r1/3 + g1/3 + b1/3));
    }
    cout<<ans;
    return 0;
}