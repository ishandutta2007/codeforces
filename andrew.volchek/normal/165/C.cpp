#include <iostream>

using namespace std;

int main()
{
	long K;
	char *A;

	cin >> K;
	cin.ignore();
	A = new char[1000001];

	cin >> A;
	long N = strlen(A);

	for(long i=0;i<N;i++)
		A[i] = A[i] - '0';
	A[N] = 1;
	N++;

	

	long l,r;
	unsigned long long ans = 0;
	unsigned long long t1,t2;
	unsigned long long sum = 0;

	l = 0;
	r = 0;

	if(K==0)
	{
		while(l < N)
		{
			t1 = 0;
			while(sum==0&&l<N)
			{
				sum += A[l];
				l++;
				t1++;
			}
			t1--;
			sum--;
			ans += (2+t1-1)*t1/2;

		}
		cout << ans;
		return 0;
	}

	while(r<N)
	{
		while(sum < K && r < N)
		{
			sum += A[r];
			r++;
		}
		if(sum == K)
		{
			t2 = 0;
			while(sum == K && r < N)
			{
				sum += A[r];
				r++;
				t2++;
			}
			//r--;
			//sum--;

			t1 = 0;
			while(sum != K)
			{
				sum -= A[l];
				l++;
				t1++;
			}
			ans += t1*t2;
		}
	}

	cout << ans;



	return 0;
}