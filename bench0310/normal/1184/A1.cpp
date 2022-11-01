#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long r;
	cin >> r;
	bool b=0;
	for(long long i=1;i*i<=r;i++)
    {
        if(r%i) continue;
        long long x=i;
        long long y=(r-x*x-x-1)/(2*x);
        if(x*x+2*x*y+x+1==r&&x>0&&y>0)
        {
            b=1;
            cout << x << " " << y << endl;
            break;
        }
        x=(r/i);
        y=(r-x*x-x-1)/(2*x);
        if(x*x+2*x*y+x+1==r&&x>0&&y>0)
        {
            b=1;
            cout << x << " " << y << endl;
            break;
        }
    }
    if(!b) cout << "NO" << endl;
	return 0;
}