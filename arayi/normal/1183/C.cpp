#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int N = 2 * 1000000;
long long int n, x, m, poqr,mec, l,r, d,q,k;
long long int   pat;
long long int a,b;
pair<long long int, long long int>t[N];
string s;
int main()
{
	cin >> q;
	for (int oo = 0; oo < q; oo++)
	{
		cin >> k >> n >> a >> b;
		if (b * n >= k)
		{
			cout << -1 << endl;
		}
 
		else {
			//m = k - n * b;
/*			{mec = n; poqr = 0;
			if (n % 2 == 0)
			{
				l = n / 2; r = l;
			}
			else { l = n / 2; r = l + 1; }
			if (l * a + r * b >= k)
			{
				m = 1;
			}
			else m = 2;
			while (7 == 7)
			{
				if (a * mec + poqr * b < k)
				{
					cout << mec << endl;
					break;
				}
				if (poqr * a + mec * b >= k)
				{
					cout << poqr - 1 << endl;
					break;
				}
				else { mec--; poqr++; }
				if (m == 1) {
					if (l * a + r * b >= k)
					{
						l--; r++;
					}
					else
					{
						cout << l << endl;
						break;
					}
				}
				if (m == 2)
				{
					if (l * a + r * b >= k)
					{
						cout << l - 1 << endl;
						break;
					}
					else {
						l++;
						r--;
					}
				}
		}}*/
			x = k - 1 - n * b;
            pat = min(n, x/(a-b));
			if(m==0)cout << pat << endl;
			
 
			//cout << m << endl;
		}pat = 0; m = 0;
	}
	
}