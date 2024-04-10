#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int hh,mm,h,d,c,n;
	cin>>hh;
	cin>>mm;
	mm=max(0,(20-hh)*60-mm);
	cin>>h;
	cin>>d;
	cin>>c;
	cin>>n;
	cout<<min(1.0*((h+n-1)/n)*c,1.0*((h+mm*d+n-1)/n)*c*0.8);
}