#include <bits/stdc++.h>

using namespace std;

int val(int a)
{
    if((a%4)==0) return 3;
    else if((a%4)==1) return 0;
    else if((a%4)==2) return 2;
    else if((a%4)==3) return 1;
}

int main()
{
	int n;
	cin >> n;
	int best=0;
	for(int i=1;i<=2;i++)
    {
        if(val(n+i)<val(n+best)) best=i;
    }
    cout << best << " " << (char)('A'+val(n+best)) << endl;
	return 0;
}