#include <iostream>

using namespace std;
const long long oo = 1e15;
long long b = 0, s = 0, c = 0, nb, ns, nc, pb, ps, pc, dw = 0, up = oo, md, r, z = 0;
bool isval()
{
	return  (max(md * b - nb, z) * pb + max(md * c - nc, z) * pc + max(md * s - ns, z) * ps > r);
}
int main()
{
	string t;
	cin >> t;
	cin >> nb;
	cin >> ns;
	cin >> nc;
	cin >> pb;
	cin >> ps;
	cin >> pc;
	cin >> r;
	for(int i = 0; i < t.size(); i ++)
	{
		if(t[i] == 'B')
		{
			b ++;
		}
		if(t[i] == 'S')
		{
			s ++;
		}
		if(t[i] == 'C')
		{
			c ++;
		}
	}
	while(up - dw > 1)
	{
		md = (up + dw) / 2;
		if(isval())
		{
			up = md;
		}
		else
		{
			dw = md;
		}
	}
	cout << dw;
	return 0;
}