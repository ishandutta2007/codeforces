#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ftype;

vector<int> a;
int n;

ftype f(ftype x)
{
	ftype maxModSum = 0;
	
	ftype sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] - x;
		if (sum < 0)
			sum = 0;
		if (sum > maxModSum)
			maxModSum = sum;
	}
	sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		sum += -(a[i] - x);
		if (sum < 0)
			sum = 0;
		if (sum > maxModSum)
			maxModSum = sum;
	}
	
	return maxModSum;
}

int main()
{
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	ftype low = -20000, high = 20000;
	
	for (int t = 0; t < 200; t++)
	{
		ftype m1 = low * 2 / 3 + high * 1 / 3;
		ftype m2 = low * 1 / 3 + high * 2 / 3;
		
		ftype vm1 = f(m1), vm2 = f(m2);
		
		if (vm1 > vm2)
			low = m1;
		else
			high = m2;
	}
	
	ftype x = (low + high) / 2;
	x = f(x);
	cout << fixed << setprecision(12) << x << endl;
	
	return 0;
}