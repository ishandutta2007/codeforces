#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,d,c=2,a[100];
	cin >> n >> d;
	for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(i&&(a[i]-a[i-1])>2*d) c+=2;
        if(i&&(a[i]-a[i-1])==2*d) c++;
    }
    cout << c << endl;
	return 0;
}