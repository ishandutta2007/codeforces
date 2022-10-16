#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int move=0 ;
	move+=min(  abs (s[0]-'a') , 26-abs(s[0]-'a')  );
    for (int i = 1; i < s.size(); ++i)
    {
    	move+=min(abs(s[i]-s[i-1]),26-abs(s[i]-s[i-1]));
    }
	cout<<move;
	return 0;
}