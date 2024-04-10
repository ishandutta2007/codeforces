#include <iostream>

using namespace std;

#define ull unsigned long long

int main()
{
	long N;

	cin >> N;

	ull A = 1;
	ull B = 1;
	ull C = 1;
	ull D = 0;

	ull A2,B2,C2,D2;

	for(long i=0;i<N-2;i++)
	{
		A2 = (B + C + D) % 1000000007;
		B2 = (A + C + D) % 1000000007;
		C2 = (B + A + D) % 1000000007;
		D2 = (A + B + C) % 1000000007;

		A = A2;
		B = B2;
		C = C2;
		D = D2;
	}

	ull ans = (A + B + C) % 1000000007;

	if(N == 1)
		cout << 0;
	else if(N == 2)
		cout << 3;
	else
		cout << ans;

	return 0;
}