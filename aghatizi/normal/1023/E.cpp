#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int n , is[maxn];

bool ask(int r1 , int c1 , int r2 , int c2)
{
	cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
	string s;
	cin >> s;

	return (s[0] == 'Y');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int x = 1 , y = 1;

	string res;
	for(int i = 0; i < n - 1; i++)
	{
		if(ask(x , y + 1 , n , n))
			res += "R" , y++;
		else
			res += "D" , x++;

	}

	x = n , y = n;

	string res2;
	for(int i = 0; i < n - 1; i++)
	{
		if(ask(1 , 1 , x - 1 , y))
			res2 += "D" , x--;
		else
			res2 += "R" , y--;
	}

	reverse(res2.begin() , res2.end());
	res += res2;

	cout << "! " << res << endl;
}