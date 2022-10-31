#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second

void secondPart(ll i, ll prev, ll k, int middle, int n)
{
	ll start = 0;
	if (middle != 1 && i == 0)
		start = 1;
	for (ll j = start; j < (1LL << (n/2)); j++)
	{
		//cout << "j " << j << endl;
		ll rev = 0;
		
		for (int h = 1; h < n/2; h++)
		{
			rev |= ((j & (1LL << h)) >> h) << (n/2 - 1 - h);
		}
		
		//cout << "rev " << rev << endl;
		
		if (j & 1)
		{
			if ((((~rev) & ((1LL << (n/2 - 1))-1)) >= i) && middle != 1)
			{
				//cout << i << " " << rev << endl;
				prev++;
			}
			else if (((~rev) & ((1LL << (n/2 - 1))-1)) > i)
			{
				//cout << i << " " << ((~rev) & ((1LL << (n/2))-1)) << endl;
				prev++;
			}			
		} 
		else
		{
			if (rev >= i)
			{
				prev++;
			}
			else if (rev > i)
			{
				prev++;
			}
		}
		
		if (prev == k)
		{
			for (int h = 0; h < n/2; h++)
			{
				if (i & (1LL << (n/2 - 1 - h)))
					cout << '1';
				else
					cout << '0';
			}
			if (middle == 1)
				cout << '1';
			else if (middle == 2)
				cout << '0';
				
			for (int h = 0; h < n/2; h++)
			{
				if (j & (1LL << (n/2 - 1 - h)))
					cout << '1';
				else
					cout << '0';
			}
			
			exit(0);
		}
		
	}
}


int main(int argc, char **argv)
{
	int n;
	ll k, curr = 0;
	cin >> n >> k;
	
	if (n & 1)
	{
		n--;
		for (ll i = 0; i < (1LL << (n/2 - 1)); i++)
		{
			ll prev = curr;
			if (i == 0)
			{
				curr += (((1LL << (n/2 - 1)) - 1) - i + 1) * 2 - 1;
			}
			else 
			{
				curr += (((1LL << (n/2 - 1)) - 1) - i + 1) * 2;
			}

			if (curr >= k)
			{
				secondPart(i, prev, k, 2, n);
				break;
			}
		
			prev = curr;
			if (i == 0)
			{
				curr += (((1LL << (n/2 - 1)) - 1) - i + 1) * 2 - 1;
			}
			else 
			{
				curr += (((1LL << (n/2 - 1)) - 1) - i + 1) * 2 - 1;
			}
			//cout << i << " " << curr << endl;
			if (curr >= k)
			{
				secondPart(i, prev, k, 1, n);
				break;
			}
		}
	}
	else
	{
		for (ll i = 0; i < (1LL << (n/2 - 1)); i++)
		{
			ll prev = curr;
			if (i == 0)
			{
				curr += (((1LL << (n/2 - 1)) - 1) - i + 1) * 2 - 1;
			}
			else 
			{
				curr += (((1LL << (n/2 - 1)) - 1) - i + 1) * 2;
			}
			
			//cout << curr - prev << endl;
			
			
			
			if (curr >= k)
			{
				//cout << "curr " << curr << endl;
				secondPart(i, prev, k, 0, n);
				break;
			}
		}
	}
	
	cout << -1;
	
	return 0;
	
}