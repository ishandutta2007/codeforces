#include <iostream>
#include <set>

using namespace std;

int main()
{
	int N,M;
	cin >> N >> M;
	cin.ignore();
	char A[100][101];
	for(int i=0;i<N;i++)
		cin >> A[i];
	set < char > S;
	unsigned long long ans = 1;
	for(int i=0;i<M;i++)
	{
		S.clear();
		for(int j=0;j<N;j++)
		{
			S.insert(A[j][i]);
		}
		ans *= S.size();
		ans = ans % 1000000007;
	}

	cout << ans;

	return 0;
}