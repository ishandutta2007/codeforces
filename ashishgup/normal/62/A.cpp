#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int gl, gr, bl, br;

int check(int a, int b)
{
	int mina=b-1;
	int extra=mina * 1 + 4;
	if(a>=mina && a<=mina+extra)
		return 1;
	return 0;
}

int checkleft()
{
	int b=br;
	int g=gl;
	return check(b, g);
}

int checkright()
{
	int b=bl;
	int g=gr;
	return check(b, g);
}

int32_t main()
{
    IOS;
    cin>>gl>>gr>>bl>>br;
    if(checkleft())
    	cout<<"YES";
    else if(checkright())
    	cout<<"YES";
    else
    	cout<<"NO";
    return 0;
}