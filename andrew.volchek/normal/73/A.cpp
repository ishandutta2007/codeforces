#include <iostream>
#include <algorithm>

using namespace std;

#define ull unsigned long long

int main()
{
	ull A[3],k;
	cin >> A[0] >> A[1] >> A[2] >> k;
	
	A[0]--;	
	A[1]--;
	A[2]--;
	
	
	ull ans = 1;

	sort(A,A+3);

	ull x,y,z;

	x = min(k/3,A[0]);
	k -= x;

	y = min(k/2,A[1]);
	k -= y;

	z = min(k,A[2]);
	k -= z;

	x++;
	y++;
	z++;

	cout << x*y*z;


	return 0;
}