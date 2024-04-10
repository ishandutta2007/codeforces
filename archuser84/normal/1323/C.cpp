#include <iostream>
#include <string.h>
#define ll long long
#define Loop(x,a,b) for(int x = a; x < b; x++)
using namespace std;

const int N = 1000000;

int main()
{
	int n;
	char c[N + 1];
	cin >> n;
	cin >> c;
	int cnt=0;
	int cnt2=0;
	Loop(i,0,n)
	{
		cnt += 2*(c[i] == '(') - 1;
		cnt2 += c[i] == '(' && cnt == 0;
		cnt2 += cnt < 0;
	}
	if(cnt)
		cout << -1;
	else
		cout << cnt2;
}