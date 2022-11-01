# include <bits/stdc++.h>

using namespace std;

const int xn = 10;
long long int a[xn];
long long int b[xn];
long long int c[xn];

int main(){
	string hmb;
	long long m;
	cin >> hmb;
	for (int i=0; i<3; i++)
		cin >> a[i];
	for (int i=0; i<3; i++)
		cin >> b[i];
	cin >> m;
	for (long long int i=0; i<hmb.size(); i++){
		if (hmb[i] == 'B')
			c[0] += 1;
		else if (hmb[i] == 'S')
			c[1] += 1;
		else
			c[2] += 1;
	}
	long long l = 0, r = 1e15;
	long long s, x;
	while (l < r){
		x = (l+r)/2;
		s = 0;
		for (int i=0; i<3; i++)
			if (((c[i]*x)-a[i])*b[i] > 0) s += ((c[i]*x)-a[i])*b[i];
		//cout << "x : " << x << " , s : " << s << " , m : " << m << endl;
		if (s > m)
			r = x;
		else if (s < m)
			l = x;
		else
			break;
		if (r-l == 1 and s < m){
			break;
		}
	}
	cout << x;
}