#include <iostream>
#include <map>

using namespace std;
/*map < int, int > mm;

int rec(int mask, int k)
{
	if (mm.find(mask) != mm.end())
		return mm[mask];
	
	int mex[100];
	for (int i = 0; i < 100; i++)
		mex[i] = 0;
	
	for (int i = 0; i < k; i++)
	{
		if (!(mask & (1 << i)))
		{
			int nmask = mask;
			for (int j = i+1; j <= k; j += (i+1))
			{
				nmask = nmask | (1 << (j-1));
			}
			
			mex[rec(nmask, k)] = 1;
		}
	}
	
	
	int ans = 0;
	while (mex[ans]) ans++;
	
	
	//cout << ans << endl;
	return mm[mask] = ans;
}*/

const int gr[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};
long long n;
int used[100000];
int cnt[33];

int main()
{
	/*for (int i = 1; i <= 30; i++)
	{
		mm.clear();
		cout << rec(0, i) << ", ";
	}
	cout << endl;*/
	cin >> n;
	long long p = 2;
	while (p*p <= n) p++;
	p--;
	long g = p;
	//p = p*p;
	//cout << p << endl;
	long long b = n - p;
	for (long long i = 2; i*i <= n; i++)
	{
		if (used[i])
			continue;
		long long d = 0;
		long long u = i;
		while (u <= n) 
		{
			if (u < 100000)
				used[u] = 1;
			d++;
			
			if (u > p)
				b--;
				
			u *= i;
		}
		//cout << i << " " << d << endl;
		cnt[d]++;
	}
	//cout << n - p << endl;
	cnt[1] += b & 1;
	
	int ans = gr[1];
	for (int i = 1; i <= 30; i++)
	{
		if (cnt[i] & 1)
			ans ^= gr[i];
	} 
	
	if (ans)
		cout << "Vasya";
	else
		cout << "Petya";
	
	
	return 0;
}