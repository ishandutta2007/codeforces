#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a,x,b,y;
	cin >> n >> a >> x >> b >> y;
	int one=a,two=b;
	bool res=0;
	while(one!=x&&two!=y)
    {
        if(one!=x)
        {
            one++;
            if(one==n+1) one=1;
        }
        if(two!=y)
        {
            two--;
            if(two==0) two=n;
        }
        if(one==two) res=1;
    }
    if(res) cout << "YES" << endl;
    else cout << "NO" << endl;
	return 0;
}