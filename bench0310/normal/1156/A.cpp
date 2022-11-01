#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++)
    {
        if((a[i]==2&&a[i+1]==3)||(a[i]==3&&a[i+1]==2))
        {
            cout << "Infinite" << endl;
            return 0;
        }
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            if(i==0||i==n-1)
            {
                if(i-1>=0) res+=(a[i-1]+1);
                if(i+1<n) res+=(a[i+1]+1);
            }
            else
            {
                if(a[i-1]==3&&a[i+1]==2) res+=6;
                else res+=(a[i-1]+a[i+1]+2);
            }
        }
    }
    cout << "Finite" << endl;
    cout << res << endl;
	return 0;
}