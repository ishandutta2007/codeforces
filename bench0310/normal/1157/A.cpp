#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt=9;
    while(n>=10)
    {
        n++;
        while((n%10)==0) n/=10;
        cnt++;
    }
    cout << cnt << endl;
	return 0;
}