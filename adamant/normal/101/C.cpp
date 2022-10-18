#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Ax, Ay, Bx, By, Cx, Cy;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
	for(int i = 0; i < 4; i++)
	{
		int tx = -Ay, ty = Ax;
		Ax = tx; Ay = ty;
		if(Ax == Bx && Ay == By)
		{
			cout << "YES\n";
			return 0;
		}
		double Dx = Bx - Ax;
		double Dy = By - Ay;
		double X = Cx;
		double Y = Cy;
		auto T = complex<double>(Dx, Dy) / complex<double>(X, Y); 
		if(abs(T.real() - round(T.real())) < 1e-12)
		if(abs(T.imag() - round(T.imag())) < 1e-12)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}