#include <iostream>

using namespace std;


int main()
{
	char *S = new char[100001];
	long N,K;
	cin >> N >> K;
	cin.ignore();
	cin >> S;
	S[N] = 0;

	for(long i=0;i<N-1&&K;i++)
	{
		if(S[i]=='4'&&S[i+1]=='7'&&S[i+2]=='7')
		{
			if((i+1)%2)
			{
				if(K%2)
				{
					S[i] = '4';
					S[i+1] = '4';
					S[i+2] = '7';
					break;
				}
				else
				{
					S[i] = '4';
					S[i+1] = '7';
					S[i+2] = '7';
					break;
				}
			}
			else
			{
				S[i] = '7';
				S[i+1] = '7';
				S[i+2] = '7';
				K--;
				//i+=3;
			}
		}
		else if(S[i]=='4'&&S[i+1]=='4'&&S[i+2]=='7')
		{
			if((i+1)%2)
			{
				if(K%2)
				{
					S[i] = '4';
					S[i+1] = '7';
					S[i+2] = '7';
					break;
				}
				else
				{
					S[i] = '4';
					S[i+1] = '4';
					S[i+2] = '7';
					break;
				}
			}
			else
			{
				S[i] = '4';
				S[i+1] = '4';
				S[i+2] = '4';
				K--;
				//i+=3;
			}
		}
		else if(S[i]=='4'&&S[i+1]=='7')
		{
			if((i+1)%2)
			{
				S[i] = '4';
				S[i+1] = '4';
				K--;
				//i+=2;
			}
			else
			{
				S[i] = '7';
				S[i+1] = '7';
				K--;
				//i+=2;
			}
		}
	}
	cout << S;
	return 0;
}