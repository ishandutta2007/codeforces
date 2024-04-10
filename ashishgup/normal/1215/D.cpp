#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, asum = 0, bsum = 0, acnt = 0, bcnt = 0;
string s;

bool leftGreedy()
{
	int lsum = asum, rsum = bsum;
	int turn = 0, ac = acnt, bc = bcnt;
	while(ac > 0)
	{
		if(!turn)
			lsum += 9;
		else
			lsum += 0;
		turn ^= 1;
		ac--;
	}
	while(bc > 0)
	{
		if(!turn)
			rsum += 0;
		else
			rsum += 9;
		turn ^= 1;
		bc--;
	}	
	return lsum <= rsum;
}

bool rightGreedy()
{
	int lsum = asum, rsum = bsum;
	int turn = 0, ac = acnt, bc = bcnt;
	while(bc > 0)
	{
		if(!turn)
			rsum += 9;
		else
			rsum += 0;
		turn ^= 1;
		bc--;
	}	
	while(ac > 0)
	{
		if(!turn)
			lsum += 0;
		else
			lsum += 9;
		turn ^= 1;
		ac--;
	}
	return rsum <= lsum;
}

int32_t main()
{
	IOS;
	cin >> n >> s;
	for(int i = 0; i < n; i++)
	{
		if(i < n / 2)
		{
			if(s[i] == '?')
				acnt++;
			else
				asum += (s[i] - '0'); 
		}
		else
		{
			if(s[i] == '?')
				bcnt++;
			else
				bsum += (s[i] - '0');
		}
	}	
	if(leftGreedy() && rightGreedy())
		cout << "Bicarp";
	else
		cout << "Monocarp";
	return 0;
}