#include <bits/stdc++.h>

using namespace std;

double ab(double a)
{
    if(a>=0.0) return a;
    else return -a;
}

int main()
{
    ios::sync_with_stdio(false);
	int n;
	cin >> n;
	double a[n];
	long long b[n];
	long long sum=0;
	for(int i=0;i<n;i++)
    {
        cin >> a[i];
        b[i]=a[i];
        if(a[i]<0)
        {
            if(ab((double)b[i]-1.0-a[i])<1.0) b[i]--;
        }
        sum+=b[i];
    }
    int idx=0;
    while(sum<0)
    {
        if(ab((double)b[idx]+1.0-a[idx])<1.0)
        {
            b[idx]++;
            sum++;
        }
        idx++;
    }
    for(int i=0;i<n;i++) cout << b[i] << "\n";
	return 0;
}