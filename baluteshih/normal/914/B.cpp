#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int num[100000],counts[100001];

int main()
{
	int n,i,tmp;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> tmp,counts[tmp]++;
	for(i=1;i<=100000;i++)	
		if(counts[i]&1)
		{
			cout << "Conan\n";
			return 0;
		}
	cout << "Agasa\n";
}