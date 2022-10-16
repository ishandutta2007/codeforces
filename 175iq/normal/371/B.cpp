#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	
	int count_a_2=0,count_a_3=0, count_a_5=0;
	while(a%2==0)
	{
		a/=2;
		count_a_2++;
	}

	while(a%3==0)
	{
		a/=3;
		count_a_3++;
	}

	while(a%5==0)
	{
		a/=5;
		count_a_5++;
	}

	int count_b_2=0,count_b_3=0, count_b_5=0;
	while(b%2==0)
	{
		b/=2;
		count_b_2++;
	}

	while(b%3==0)
	{
		b/=3;
		count_b_3++;
	}

	while(b%5==0)
	{
		b/=5;
		count_b_5++;
	}

	if(a==b)
	{
		int answer= abs(count_a_2-count_b_2) + abs(count_a_3-count_b_3) + abs(count_a_5-count_b_5) ; 
		cout<<answer;
	} 

	else
	{
		cout<<-1;
	}
	return 0;
}