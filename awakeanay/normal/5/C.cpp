#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

int main()
{
	std::ios::sync_with_stdio(false);
	
	std::string input;
	std::cin >> input;
	
	long int N = input.length();
	std::stack<long int> openB;
	long int a[N], b[N];
	long int max = 0;
	long int count = 1;
	
	for(long int i = 0; i < N; i++)
	{
		a[i] = b[i] = -1;
		if(input.at(i) == '(')
			openB.push(i);
		else
		{
			if(!openB.empty())
			{
				long int lastO = openB.top(); openB.pop();
				a[i] = lastO;
				b[i] = lastO;
				
				if(a[i] > 0 && b[a[i]-1] != -1)
					b[i] = b[a[i]-1];
				
				if(i - b[i] + 1 > max)
				{
					max = i - b[i] + 1;
					count = 1;
				}
				else if(i - b[i] + 1 == max)
					count++;
			}
		}
	}
	
	std::cout << max << " " << count;
	
	return 0;
}