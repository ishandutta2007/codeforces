#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,k;
	cin >> n >> k;
	if(k*(k+1)/2>n) cout << "NO" << endl;
	else
    {
        vector<long long> v(k);
        for(int i=0;i<k;i++) v[i]=i+1;
        n-=(k*(k+1)/2);
        long long q=n/k;
        for(int i=0;i<k;i++) v[i]+=q;
        n-=k*q;
        for(int i=k-1;i>0;i--)
        {
            long long t=min(2*v[i-1]-v[i],n);
            v[i]+=t;
            n-=t;
        }
        if(n) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for(int i=0;i<k;i++) cout << v[i] << " ";
            cout << endl;
        }
    }
	return 0;
}