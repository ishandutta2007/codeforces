#include <bits/stdc++.h>

using namespace std;

int sum(int a)
{
    int res=0;
    while(a)
    {
        res+=(a%10);
        a/=10;
    }
    return res;
}

int main()
{
	int a;
	cin >> a;
	for(int i=a;;i++)
    {
        if((sum(i)%4)==0)
        {
            cout << i << endl;
            break;
        }
    }
	return 0;
}