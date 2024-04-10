#include <bits/stdc++.h>

using namespace std;

string answer;

void solveTwo(int a, char ca, int b, char cb, char other)
{
	if (a == 0)
		answer += cb;
	else if (b == 0)
		answer += ca;
	else if (a > 1 && b > 1)
		answer += ca, answer += cb, answer += other;
	else if (a == 1 && b == 1)
		answer += other;
	else if (a > 1 && b == 1)
		answer += other, answer += cb;
	else
		answer += other, answer += ca;
}

int main()
{
	int n;
	cin >> n;
	
	string colors;
	cin >> colors;
	
	int nRed = 0, nGreen = 0, nBlue = 0;
	for (int i = 0; i < n; i++)
	{
		if (colors[i] == 'R') nRed++;
		if (colors[i] == 'G') nGreen++;
		if (colors[i] == 'B') nBlue++;
	}
	
	if (nGreen > 0 && nRed > 0 && nBlue > 0) answer = "RGB";
	else if (nRed == 0) solveTwo(nGreen, 'G', nBlue, 'B', 'R');
	else if (nGreen == 0) solveTwo(nRed, 'R', nBlue, 'B', 'G');
	else
	{
		assert(nBlue == 0);
		solveTwo(nRed, 'R', nGreen, 'G', 'B');
	}
	
	sort(answer.begin(), answer.end());
	cout << answer << endl;
	
	return 0;
}